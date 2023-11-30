# Chat-bot 

*by* [Tritium-chuan](https://github.com/Tritium-chuan)

## Abstract

`Chat-bot` is a chat robot that can be run entirely locally. Speech-to-text model [Whisper](https://github.com/openai/whisper), large-language model [llama](https://github.com/facebookresearch/llama), and text-to-speech model [PaddleSpeech](https://github.com/PaddlePaddle/PaddleSpeech) are ultilized in this project.

## Platform Support

The `Chat-bot` can only be comipled and run in Apple macOS. 

Make sure that the platform has an Apple M series chip with at least 16 GB unified memory. 

The test platform is MacBook Pro (14 inch, late 2023) with M3 Pro chip (11 cpu cores, 14 gpu cores, and 18 GB unified memory). 

## Installation

### Create Environment

Install [Anaconda](https://www.anaconda.com).

Create environment: `Chatbot`.

```shell
conda create -m Chatbot python=3.8.18
```

You can also create `conda` environment according to the configuration file.

```shell
conda env create -f conda-env-chatbot.yaml
```

Activate environment: `Chatbot`.

```shell
conda activate Chatbot
```

Install [PaddlePaddle](https://www.paddlepaddle.org.cn/en). 

Install [opencc](https://formulae.brew.sh/formula/opencc) and [ffmpeg](https://formulae.brew.sh/formula/ffmpeg#default).

### File Setup

Create `Chat-bot-dir`.

```shell
mkdir Chat-bot-dir
cd Chat-bot-dir
mkdir llama-models
mkdir whisper-models
```

Clone the project.

```shell
git clone https://github.com/Tritium-chuan/Chat-bot.git
```

Compile Chat-bot using `g++`.

> Compile main.cpp and main-ch.cpp.

Clone [Whisper.cpp](https://github.com/ggerganov/whisper.cpp), [llama.cpp](https://github.com/ggerganov/llama.cpp), and [PaddleSpeech](https://github.com/PaddlePaddle/PaddleSpeech).

```shell
git clone https://github.com/ggerganov/whisper.cpp
git clone https://github.com/ggerganov/llama.cpp
git https://github.com/PaddlePaddle/PaddleSpeech
```

Complie `Whisper.cpp` and `llama.cpp` using `make`.

> Read `README.md` files in `Whisper.cpp` and `llama.cpp`. Make sure that the [server](https://github.com/ggerganov/whisper.cpp/tree/6559b538e5e05cfa199c15d46ca5bd0edd353974/examples/server) of Whisper.cpp and [server](https://github.com/ggerganov/llama.cpp/tree/1f5cd83275fabb43f2ae92c30033b384a3eb37b4/examples/server) of Llama.cpp is compiled and ready to use. 

Install `PaddleSpeech`.

```shell
cd PaddleSpeech
pip install pytest-runner
pip install .
```

### Model Download

English Llama models can be downloaded from [Meta](https://ai.meta.com/llama/#download-the-model). 

Chinese Llama models can be downloaded [here](https://github.com/ymcui/Chinese-LLaMA-Alpaca-2).

Place llama models `.gguf` files in llama-models folder.

> For example, `ggml-model-q4_0.gguf` file of 7B-chat model should be placed in `Chat-bot-dir/llama-models/7B-chat` folder; `ggml-model-q4_0.gguf` file of 7B-Chinese model should be placed in `Chat-bot-dir/llama-models/7B-ch` folder.

Whisper modela can be downloaded [here](https://huggingface.co/ggerganov/whisper.cpp/tree/main).

Place whisper models `.bin` files in whisper-models folder.

> To ensure accurate recognition of Chinese speech, large model is needed.
>
> For example, `ggml-large-v1.bin` should be placed in `Chat-bot-dir/whisper-models/` folder.

`PaddleSpeech` models will be downloaded automatically when using `Chat-bot`.

Check `Chat-bot-dir`. 

```shell
.
├── Chat-bot
│
├── PaddleSpeech
│
├── llama-cpp
│
├── llama-models
│   ├── 7B-ch
│   └── 7B-chat
├── whisper-cpp
│
└── whisper-models
    └── ggml-large-v1.bin
```

## Usage

### Activate Environment

```shell
conda activate Chatbot
```

### Chat in Chinese

Start `Whisper` server.

```shell
./server-whisper-ch.sh
```

Start `llama` server.

```shell
./server-llama-ch.sh
```

Start `PaddleSpeech` server.

```shell
./server-pds.sh
```

Start `Chat-bot` server.

```shell
./server-chat-ch.sh
```

Start `main-ch`.

```shell
./main-ch
```

### Chat in English

Start `Whisper` server.

```shell
./server-whisper.sh
```

Start `llama` server.

```shell
./server-llama.sh
```

Start `Chat-bot` server.

```shell
./server-chat.sh
```

Start `main`.

```shell
./main
```

> Always make sure that the servers are all using different ports. See `Note.md` for more information.
>
> Check the paths to the models before using. Modify them if you are using different models.

## Issues

`PaddleSpeech` server cannot work properly in English mode. 

## Acknowledgement

The author would like to thank `ChatGPT` for assisting writing codes and reading development documents.
