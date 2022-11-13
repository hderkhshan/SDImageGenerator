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

#ifndef DIFFUSIONOPTIONS_H
#define DIFFUSIONOPTIONS_H

#include <QObject>
#include <qqml.h>


class DiffusionOptions : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString prompt READ prompt WRITE setPrompt CONSTANT)
    Q_PROPERTY(qreal scale READ scale WRITE setScale CONSTANT)
    Q_PROPERTY(qreal imageWidth READ imageWidth WRITE setImageWidth CONSTANT)
    Q_PROPERTY(qreal imageHeight READ imageHeight WRITE setImageHeight CONSTANT)
    Q_PROPERTY(qreal numberOfImages READ numberOfImages WRITE setNumberOfImages CONSTANT)
    Q_PROPERTY(qreal ddimSteps READ ddimSteps WRITE setDdimSteps CONSTANT)
    Q_PROPERTY(QString sampler READ sampler WRITE setSampler CONSTANT)
    Q_PROPERTY(QString seed READ seed WRITE setSeed CONSTANT)
    Q_PROPERTY(QString saveDir READ saveDir WRITE setSaveDir CONSTANT)
    Q_PROPERTY(bool grid READ grid WRITE setGrid CONSTANT)
    Q_PROPERTY(bool seamless READ seamless WRITE setSeamless CONSTANT)
    Q_PROPERTY(bool fullPrecision READ fullPrecision WRITE setFullPrecision CONSTANT)
    Q_PROPERTY(bool upscaler READ upscaler WRITE setUpscaler CONSTANT)
    Q_PROPERTY(QString upscaleFactor READ upscaleFactor WRITE setUpscaleFactor CONSTANT)
    Q_PROPERTY(qreal upscaleStrength READ upscaleStrength WRITE setUpscaleStrength CONSTANT)
    Q_PROPERTY(bool faceRestoration READ faceRestoration WRITE setFaceRestoration CONSTANT)
    Q_PROPERTY(qreal faceRestorationStrength READ faceRestorationStrength WRITE setFaceRestorationStrength CONSTANT)
    Q_PROPERTY(bool saveOriginalImage READ saveOriginalImage WRITE setSaveOriginalImage CONSTANT)
    Q_PROPERTY(bool imageToImage READ imageToImage WRITE setImageToImage CONSTANT)
    Q_PROPERTY(bool fitImage READ fitImage WRITE setFitImage CONSTANT)
    Q_PROPERTY(qreal imageToImageStrength READ imageToImageStrength WRITE setImageToImageStrength CONSTANT)
    Q_PROPERTY(QString initImagePath READ initImagePath WRITE setInitImagePath CONSTANT)
    Q_PROPERTY(qreal variationAmount READ variationAmount WRITE setVariationAmount CONSTANT)
    Q_PROPERTY(bool fixHighRes READ fixHighRes WRITE setFixHighRes CONSTANT)
    Q_PROPERTY(QString faceRestorationMethod READ faceRestorationMethod WRITE setFaceRestorationMethod CONSTANT)
    Q_PROPERTY(QString maskImagePath READ maskImagePath WRITE setMaskImagePath CONSTANT)
    Q_PROPERTY(bool useMaskImage READ useMaskImage WRITE setUseMaskImage CONSTANT)
    Q_PROPERTY(QString tiConceptStyle READ tiConceptStyle WRITE setTiConceptStyle CONSTANT)
    Q_PROPERTY(bool useTextualInversion READ useTextualInversion WRITE setUseTextualInversion CONSTANT)
    Q_PROPERTY(QString tiConceptDirectory READ tiConceptDirectory WRITE setTiConceptDirectory CONSTANT)
    Q_PROPERTY(bool acceptedTerms READ acceptedTerms WRITE setAcceptedTerms CONSTANT)
    Q_PROPERTY(QString appPath READ appPath WRITE setAppPath CONSTANT)
    QML_ELEMENT

public:
    using QObject::QObject;

    const QString &prompt() const;
    void setPrompt(const QString &newPrompt);

    qreal scale() const;
    void setScale(qreal newScale);

    qreal imageWidth() const;
    void setImageWidth(qreal newImageWidth);

    qreal imageHeight() const;
    void setImageHeight(qreal newImageHeight);

    qreal numberOfImages() const;
    void setNumberOfImages(qreal newNumberOfImages);

    qreal ddimSteps() const;
    void setDdimSteps(qreal newDdimSteps);

    const QString &sampler() const;
    void setSampler(const QString &newSampler);

    QString seed() const;
    void setSeed(const QString &newSeed);

    const QString &saveDir() const;
    void setSaveDir(const QString &newSaveDir);

    bool grid() const;
    void setGrid(bool newGrid);

    bool seamless() const;
    void setSeamless(bool newSeamless);

    bool fullPrecision() const;
    void setFullPrecision(bool newFullPrecision);

    bool upscaler() const;
    void setUpscaler(bool newUpscaler);

    const QString &upscaleFactor() const;
    void setUpscaleFactor(const QString &newUpscaleFactor);

    qreal upscaleStrength() const;
    void setUpscaleStrength(qreal newUpscaleStrength);

    bool faceRestoration() const;
    void setFaceRestoration(bool newFaceRestoration);

    qreal faceRestorationStrength() const;
    void setFaceRestorationStrength(qreal newFaceRestorationStrength);

    bool saveOriginalImage() const;
    void setSaveOriginalImage(bool newSaveOriginalImage);

    bool imageToImage() const;
    void setImageToImage(bool newImageToImage);

    bool fitImage() const;
    void setFitImage(bool newFitImage);

    qreal imageToImageStrength() const;
    void setImageToImageStrength(qreal newImageToImageStrength);

    const QString &initImagePath() const;
    void setInitImagePath(const QString &newInitImagePath);

    qreal variationAmount() const;
    void setVariationAmount(qreal newVariationAmount);

    bool fixHighRes() const;
    void setFixHighRes(bool newFixHighRes);

    const QString &faceRestorationMethod() const;
    void setFaceRestorationMethod(const QString &newFaceRestorationMethod);

    const QString &maskImagePath() const;
    void setMaskImagePath(const QString &newMaskImagePath);

    bool useMaskImage() const;
    void setUseMaskImage(bool newUseMaskImage);

    const QString &tiConceptStyle() const;
    void setTiConceptStyle(const QString &newTiConceptStyle);

    bool useTextualInversion() const;
    void setUseTextualInversion(bool newUseTextualInversion);

    const QString &tiConceptDirectory() const;
    void setTiConceptDirectory(const QString &newTiConceptDirectory);

    const QString &appPath() const;
    void setAppPath(const QString &newAppPath);

    bool acceptedTerms() const;
    void setAcceptedTerms(bool newAcceptedTerms);

private:
    QString m_prompt;
    qreal m_scale;
    qreal m_imageWidth;
    qreal m_imageHeight;
    qreal m_numberOfImages;
    qreal m_ddimSteps;
    QString m_sampler;
    QString m_seed;
    QString m_saveDir;
    bool m_grid;
    bool m_seamless;
    bool m_fullPrecision;
    bool m_upscaler;
    QString m_upscaleFactor;
    qreal m_upscaleStrength;
    bool m_faceRestoration;
    qreal m_faceRestorationStrength;
    bool m_saveOriginalImage;
    bool m_imageToImage;
    bool m_fitImage;
    qreal m_imageToImageStrength;
    QString m_initImagePath;
    qreal m_variationAmount;
    bool m_fixHighRes;
    QString m_faceRestorationMethod;
    QString m_maskImagePath;
    bool m_useMaskImage;
    QString m_tiConceptStyle;
    bool m_useTextualInversion;
    QString m_tiConceptDirectory;
    QString m_appPath;
    bool m_acceptedTerms;

};

#endif // DIFFUSIONOPTIONS_H
