import os


# Define metrics to calculate (PSNR, SSIM, VMAF)
metrics = ["psnr", "ssim", "vmaf"]

# Example reference and distorted video files
reference_file = "reference.mp4"
distorted_file = "distorted.mp4"

# Construct the command string
command = (
    f"ffmpeg-quality-metrics {reference_file} {distorted_file} --metrics {' '.join(metrics)} -of csv > output.csv"
)

# Execute the command
os.system(command)

print(f"Metrics saved to output.csv")
