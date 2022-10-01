#ifndef DEFINES_H
#define DEFINES_H

static const char* MINICONDA_ENV_DIRECTORY_WIN = "sdenv/mf";
static const char* CURL_DIRECTORY_WIN = "curl/bin/curl.exe";
static const char* CONDA_ACTIVATE_SCRIPT_WIN = "condabin/activate.bat";
static const char* PYTHON_ENV_DIRECTORY = "env";
static const char* STABLE_DIFFUSION_DIRECTORY = "sdenv/stablediffusion";
static const char* STABLE_DIFFUSION_MODEL_1_4 = "models/ldm/stable-diffusion-v1/model.ckpt";
static const qint64 STABLE_DIFFUSION_MODEL_1_4_FILE_SIZE = 4265380512;
static const char* STABLE_DIFFUSION_MODEL_1_4_URL = "https://www.googleapis.com/storage/v1/b/aai-blog-files/o/sd-v1-4.ckpt?alt=media";
static const char* STABLE_DIFFUSION_RESULTS_FOLDER_NAME = "results";
static const char* STABLE_DIFFUSION_DREAM = "scripts/dream.py";
static const char* STABLE_DIFFUSION_ENVIRONMENT_YAML ="environment.yaml";
static const char* LOG_FILE_NAME = "SdImageGenerator_logs.txt";

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
static const char* DEFAULT_UPSCALE_FACTOR = "2x";
static const double DEFAULT_UPSCALE_STREGTH = 0.75;

#endif // DEFINES_H

