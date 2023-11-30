paddlespeech tts --am fastspeech2_mix --voc hifigan_csmsc --lang mix --input "$1" --spk_id 174 --output output.wav
afplay output.wav 