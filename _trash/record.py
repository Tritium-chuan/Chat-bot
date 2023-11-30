import tkinter as tk
import sounddevice as sd
import numpy as np
import soundfile as sf
import wave

class AudioRecorderApp:
    def __init__(self, master):
        self.master = master
        self.is_recording = False

        self.start_button = tk.Button(master, text="Start Recording", command=self.toggle_recording)
        self.start_button.pack(pady=10)

    def toggle_recording(self):
        if not self.is_recording:
            self.start_recording()
        else:
            self.stop_recording()

    def start_recording(self):
        self.is_recording = True
        self.start_button.config(text="Stop Recording")

        # 设置音频参数
        sample_rate = 44100
        channels = 1
        duration = 5  # 录音时长（秒）
        filename = "recorded_audio.wav"

        # 录音回调函数
        def callback(indata, frames, time, status):
            if status:
                print(status, flush=True)
            frames = indata.flatten()
            self.recorded_frames.extend(frames)

        # 初始化录音参数
        self.recorded_frames = []
        self.stream = sd.InputStream(callback=callback, channels=channels, samplerate=sample_rate)
        self.stream.start()

        # 设置定时器，在指定时间后停止录音
        self.master.after(int(duration * 1000), self.stop_recording)

    def stop_recording(self):
        self.is_recording = False
        self.start_button.config(text="Start Recording")

        # 停止录音
        self.stream.stop()
        self.stream.close()

        # 保存录音为WAV文件
        sample_width = 2  # 16位样本，每个样本2字节
        frames = np.array(self.recorded_frames)
        frames = frames.astype(np.int16)

        sample_rate = 44100
        sf.write("recorded_audio.wav", frames, sample_rate)
        # with wave.open("recorded_audio.wav", "wb") as wf:
        #     wf.setnchannels(1)
        #     wf.setsampwidth(sample_width)
        #     wf.setframerate(44100)
        #     wf.writeframes(frames.tobytes())

        # sd.play(frames, sample_rate)

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Audio Recorder")
    app = AudioRecorderApp(root)
    root.mainloop()
