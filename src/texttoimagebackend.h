/*
    SDImageGenerator, Text to image generation AI app
    Copyright(C) 2022 Rupesh Sreeraman
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef TEXTTOIMAGEBACKEND_H
#define TEXTTOIMAGEBACKEND_H

#include "diffusionenvironment.h"
#include "diffusionenvironmentstatus.h"
#include "diffusionenvvalidator.h"
#include "diffusionoptions.h"
#include "diffusionprocess.h"
#include "settings.h"
#include "installer/devicedetector.h"
#include "installer/installerprocess.h"
#include "installer/modelsfinder.h"
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QObject>
#include <qqml.h>
#include <QUrl>

#ifdef Q_OS_WIN
  #include <windows.h>
#endif


class TextToImageBackend : public QObject,public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(QString errorMessage MEMBER errorMsg NOTIFY gotErrorMessage)
    Q_PROPERTY(QString diffusionStatusMessage MEMBER diffusionStatusMsg NOTIFY statusChanged)
    Q_PROPERTY(QUrl samplesUrl MEMBER samplesPath NOTIFY samplesPathChanged)
    Q_PROPERTY(DiffusionOptions* options READ options CONSTANT)
    Q_PROPERTY(DiffusionEnvironmentStatus* envStatus READ envStatus CONSTANT)
    Q_PROPERTY(bool isProcessing MEMBER isProcessing NOTIFY isProcessingChanged)
    Q_PROPERTY(bool isCancelled MEMBER isCancelled NOTIFY isCancelledChanged)
    Q_PROPERTY(bool isModelLoaded MEMBER isModelLoaded NOTIFY isModelLoadedChanged)
    Q_PROPERTY(QStringList tiConcepts MEMBER tiConcepts NOTIFY tiConceptsChanged)
    Q_PROPERTY(QStringList stableDiffusionModels MEMBER stableDiffusionModels NOTIFY stableDiffusionModelsChanged)
    Q_PROPERTY(bool isStableDiffusionModelLoading MEMBER isStableDiffusionModelLoading NOTIFY isStableDiffusionModelLoadingChanged)

public:
    explicit TextToImageBackend(QObject *parent = nullptr);

    DiffusionOptions *options() const;
    void setOptions(DiffusionOptions *newOptions);
    void classBegin();
    void componentComplete();

    bool getIsProcessing() const;
    void setIsProcessing(bool newIsProcessing);

    DiffusionEnvironmentStatus *envStatus() const;
    void setEnvStatus(DiffusionEnvironmentStatus *newEnvStatus);

    bool getIsCancelled() const;
    void setIsCancelled(bool newIsCancelled);

    bool getIsModelLoaded() const;
    void setIsModelLoaded(bool newIsModelLoaded);

    const QStringList &getTiConcepts() const;
    void setTiConcepts(const QStringList &newTiConcepts);

    const QStringList &getStableDiffusionModels() const;
    void setStableDiffusionModels(const QStringList &newStableDiffusionModels);

    bool getIsStableDiffusionModelLoaded() const;
    void setIsStableDiffusionModelLoaded(bool newIsStableDiffusionModelLoaded);

public slots:
    void generateImage(bool isVariation);
    void stopProcessing();
    void showErrorDlg(const QString &errorMesg);
    void saveSettings();
    void loadSettings();
    void resetSettings();
    void stableDiffusionFinished();
    void openOutputFolder();
    void setOutputFolder(QUrl url);
    void generatingImages();
    void imagesGenerated();
    void updateCompleted();
    void openLogs();
    void downloadModel();
    void installPythonEnv();
    void stopInstaller();
    void stopDownloader();
    void cudaMemoryError();
    void environmentCurrentStatus(bool isPackagesReady,bool isStableDiffusionModelReady);
    void handlePackagesStatus(bool isPackagesReady);
    void handleModelStatus(bool isModelReady);
    void downloadGfpganModel();
    void setImageInput(QUrl url);
    void generateVariations(QUrl imagePath);
    void downloadCodeFormerModel();
    void setMaskImageInput(QUrl url);
    void diffusionCancelled();
    void updateDeviceInfo(QString);
    void initAppControls(bool packageReady,bool stableDiffusionModelReady);
    void showTermsWindow();
    void setTextualInversionFolder(QUrl url);
    void gotModelsList(QStringList);
    void switchModel(QString modelName);
    void stableDiffusionModelLoaded(bool isLoaded);

signals:
    void showMessageBox();
    void gotErrorMessage();
    void statusChanged();
    void samplesPathChanged();
    void initControls(DiffusionOptions* options,DiffusionEnvironmentStatus *envStatus);
    void promptTextChanged();
    void guidanceScaleChanged();
    void imageWidthChanged();
    void setOutputDirectory(QString);
    void isProcessingChanged();
    void environmentNotReady();
    void installerStatusChanged(const QString &msg, float downloadPercentage);
    void downloaderStatusChanged(const QString &msg, float downloadPercentage);
    void downloadPercentageChanged();
    void setupInstallerUi(bool isDownloader);
    void closeLoadingScreen();
    void setInputImagePath(QString);
    void showDreamPage();
    void setInputMaskImagePath(QString);
    void isCancelledChanged();
    void isModelLoadedChanged();
    void tiConceptsChanged();
    void showTermsDialog(QString terms);
    void setTiDirectory(QString);
    void stableDiffusionModelsChanged();
    void isStableDiffusionModelLoadingChanged();

private:
    DiffusionProcess *stableDiffusion;
    DiffusionEnvironment *diffusionEnv;
    DiffusionOptions *m_options;
    DiffusionEnvironmentStatus *m_envStatus;
    DiffusionEnvValidator *envValidator;

    InstallerProcess *modelDownloader;
    InstallerProcess *pythonEnvInstaller;
    Settings *appSettings;

    QString errorMsg;
    QString diffusionStatusMsg;
    QUrl samplesPath;
    bool isProcessing;
    QString curOutputFolder;
    QString deafultAssetsPath;
    QString installerStatusMsg;
    bool isCancelled;
    bool isModelLoaded;
    QStringList tiConcepts;
    DeviceDetector *deviceDetector;
    ModelsFinder *modelsFinder;
    QStringList stableDiffusionModels;
    bool isStableDiffusionModelLoading;

private slots:
    void updateStatusMessage(const QString&);
    void updateInstallerStatusMessage(const QString&);
    void updateDownloaderStatusMessage(const QString&);
    void installCompleted(int exitCode,bool isDownloader);
    QString getSeedFromFileName(QUrl filePath) ;
    bool isValidInitImage();
    void setupDownlodUi();
    void loadTiConceptsNamesFromFolder(const QString& path);


};

#endif // TEXTTOIMAGEBACKEND_H
