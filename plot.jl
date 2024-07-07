# Import necessary packages
using Pkg
Pkg.add("JSON")
Pkg.add("Plots")

using JSON
using Plots

# Load the JSON data
file_path = "./tos_500_5_0.json"
json_data = JSON.parsefile(file_path)

# Extract n and metric values
n_values = [entry["n"] for entry in json_data["vmaf"]]
vmaf_values = [entry["vmaf"] for entry in json_data["vmaf"]]
psnr_avg_values = [entry["psnr_avg"] for entry in json_data["psnr"]]
ssim_avg_values = [entry["ssim_avg"] for entry in json_data["ssim"]]
mse_avg_values = [entry["mse_avg"] for entry in json_data["psnr"]]


# Create the individual bar plots
plot1 = plot(n_values, vmaf_values, xlabel="n", ylabel="VMAF", title="n vs VMAF", legend=false, size=(800, 400))
plot2 = plot(n_values, psnr_avg_values, xlabel="n", ylabel="PSNR Avg", title="n vs PSNR Avg", legend=false, size=(800, 400))
plot3 = plot(n_values, mse_avg_values, xlabel="n", ylabel="MSE Avg", title="n vs MSE Avg", legend=false, size=(800, 400))
plot4 = plot(n_values, ssim_avg_values, xlabel="n", ylabel="SSIM Avg", title="n vs SSIM Avg", legend=false, size=(800, 400))

# Combine the plots into one layout
combined_plot = plot(plot1, plot2, plot3, plot4, layout = @layout([a; b; c; d]), size=(2400, 1300))

# Save the combined plot as an image
savefig(combined_plot, "combined_n_vs_metrics_bar.png")

