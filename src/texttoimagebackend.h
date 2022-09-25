#ifndef TEXTTOIMAGEBACKEND_H
#define TEXTTOIMAGEBACKEND_H

#include <QObject>
#include <QSettings>
#include "diffusionprocess.h"
#include "diffusionenvironment.h"
#include "diffusionenvvalidator.h"
#include "diffusionoptions.h"
#include "diffusionenvironmentstatus.h"
#include "installer/installerprocess.h"
#include <QDebug>
#include <qqml.h>
#include <QUrl>
#include <QTimer>
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
   // Q_PROPERTY(QString installerStatusMessage MEMBER installerStatusMsg NOTIFY installerStatusChanged)
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

public slots:
    void generateImage();
    void stopProcessing();
    void showErrorDlg(const QString &errorMesg);
    void saveSettings();
    void loadSettings();
    void resetSettings();
    void stableDiffusionFinished();
    void openOutputFolder();
    void setOutputFolder(QUrl url);
    void installEnvironment();
    void generatingImages();
    void imagesGenerated();
    void updateCompleted();
    void openLogs();
    void downloadModel();
    void installPythonEnv();
    void stopInstaller();
    void stopDownloader();
    void cudaMemoryError();

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


private:
    DiffusionProcess *stableDiffusion;
    DiffusionEnvironment *diffusionEnv;
    DiffusionOptions *m_options;
    DiffusionEnvironmentStatus *m_envStatus;
    DiffusionEnvValidator *envValidator;
    QSettings *settings;
    InstallerProcess *modelDownloader;
    InstallerProcess *pythonEnvInstaller;
    //float downloadPercentage;

    QString errorMsg;
    QString diffusionStatusMsg;
    QUrl samplesPath;
    bool isProcessing;
    QString curOutputFolder;
    QString deafultAssetsPath;
    QString installerStatusMsg;

    void initBackend();
    bool verifyEnvironment();

private slots:
    void updateStatusMessage(const QString&);
    void updateInstallerStatusMessage(const QString&);
    void updateDownloaderStatusMessage(const QString&);
    void installCompleted(int exitCode,bool isDownloader);

};

#endif // TEXTTOIMAGEBACKEND_H
