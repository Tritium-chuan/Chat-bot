curl 127.0.0.1:8042/inference -H "Content-Type: multipart/form-data" -F file=@./input_std.wav -F response-format="txt">./input.txt
opencc -i "input.txt" -o "input.txt" -c "t2s.json"