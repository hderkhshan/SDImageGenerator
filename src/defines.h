#ifndef DEFINES_H
#define DEFINES_H

#include <QtGlobal>

static const char* MINICONDA_ENV_DIRECTORY_WIN = "sdenv/mf";
static const char* CURL_DIRECTORY_WIN = "curl/bin/curl.exe";
static const char* CONDA_ACTIVATE_SCRIPT_WIN = "condabin/activate.bat";
static const char* PYTHON_ENV_DIRECTORY = "env";
static const char* STABLE_DIFFUSION_DIRECTORY = "sdenv/stablediffusion";
static const char* STABLE_DIFFUSION_MODEL_1_4 = "models/ldm/stable-diffusion-v1/sd-v1-4.ckpt";
static const qint64 STABLE_DIFFUSION_MODEL_1_4_FILE_SIZE = 4265380512;
static const char* STABLE_DIFFUSION_MODEL_1_4_URL = "https://www.googleapis.com/storage/v1/b/aai-blog-files/o/sd-v1-4.ckpt?alt=media";
static const char* STABLE_DIFFUSION_RESULTS_FOLDER_NAME = "results";
static const char* STABLE_DIFFUSION_DREAM = "scripts/invoke.py";
static const char* STABLE_DIFFUSION_ENVIRONMENT_YAML ="environment.yaml";
static const char* LOG_FILE_NAME = "SdImageGenerator_logs.txt";
static const char* GFP_GAN_PATH = "src/gfpgan";
static const char* GFP_GAN_MODEL = "experiments/pretrained_models/GFPGANv1.4.pth";
static const char* GFP_GAN_MODEL_URL = "https://github.com/TencentARC/GFPGAN/releases/download/v1.3.0/GFPGANv1.4.pth";
static const qint64 GFP_GAN_MODEL_FILE_SIZE = 348632874;
static const char* LIBS_TEST_SCRIPT = "scripts/libstest.py";
static const char* CODE_FORMER_MODEL_URL = "https://github.com/sczhou/CodeFormer/releases/download/v0.1.0/codeformer.pth";
static const char* CODE_FORMER_MODEL_PATH = "ldm/invoke/restoration/codeformer/weights/codeformer.pth";
static const qint64 CODE_FORMER_FILE_SIZE = 376637898;
static const char* TEXTUAL_INVERSION_DIR = "textual-inversion";
static const char* TEXTUAL_INVERSION_CONCEPT_FILE = "learned_embeds.bin";
static const char* DETECT_DEVICE_SCRIPT = "scripts/detect_device.py";

static const double DEFAULT_SCALE = 7.5;
static const double DEFAULT_IMAGE_WIDTH = 512;
static const double DEFAULT_IMAGE_HEIGHT = 512;
static const double DEFAULT_NUMBER_OF_IMAGES = 1;
static const double DEFAULT_DDIM_STEPS = 50;
static const char* DEFAULT_SAMPLER = "k_lms";
static const char* DEFAULT_SEED = "";
static const bool  DEFAULT_GRID = false;
static const bool  DEFAULT_SEAMLESS = false;
static const bool  DEFAULT_FULL_PRECISION = false;
static const bool  DEFAULT_USE_UPSCALER = false;
static const bool  DEFAULT_USE_FACE_RESTORATION = false;
static const bool  DEFAULT_SAVE_ORIGINAL_IMAGE = false;
static const bool  DEFAULT_USE_IMG_TO_IMG = false;
static const bool  DEFAULT_IMG_TO_IMG_FIT = false;
static const char* DEFAULT_UPSCALE_FACTOR = "2x";
static const double DEFAULT_UPSCALE_STRENGTH = 0.75;
static const double  DEFAULT_FACE_RESTORATION_STRENGTH = 0.75;
static const double  DEFAULT_IMG_TO_IMG_STRENGTH = 0.75;
static const char* DEFAULT_INIT_IMAGE = "";
static const double DEFAULT_VARIATION_AMOUNT = 0.2;
static const bool  DEFAULT_HIGHRES_FIX = false;
static const char* DEFAULT_FACE_RESTORATION_METHOD = "GFPGAN";
static const bool  DEFAULT_USE_CUSTOM_MODEL = false;

#endif // DEFINES_H

