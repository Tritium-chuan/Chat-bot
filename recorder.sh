rm -f input.wav
rm -f input_std.wav
GREEN='\033[0;32m'
NC='\033[0m'

# Start recording
echo "${GREEN}Start recording audio, press ENTER to end.${NC}"
ffmpeg -f avfoundation -i ":0" input.wav &> /dev/null &
# Use this when using Airpods:
# ffmpeg -f avfoundation -i ":1" input.wav &> /dev/null &
PID=$!

# Wait for ENTER
read -p ""

# End 
kill $PID
ffmpeg -i input.wav -ar 16000 -ac 1 -c:a pcm_s16le input_std.wav &> /dev/null &

# Change signal
echo "2" > ChatMode.flag