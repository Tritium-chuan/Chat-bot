paddlespeech_client tts_online --server_ip 127.0.0.1 --port 8092 --protocol http --input "$1" --output output.wav
afplay output.wav 