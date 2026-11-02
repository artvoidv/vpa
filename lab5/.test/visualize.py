import matplotlib.pyplot as plt

files = {
    "unoptimized random": "results_unoptimized_rand",
    "optimized random": "results_optimized_rand",
    "unoptimized": "results_unoptimized",
    "optimized": "results_optimized",
}

for name, filename in files.items():
    with open(filename) as f:
        values = [float(line) for line in f if line.strip()]
        print(name + ": " + str(f"{sum(values) / len(values):.6f}"))
    plt.plot(values, label=name)

plt.xlabel("Номер запуска")
plt.ylabel("Время, секунды")
plt.legend()
plt.tight_layout()
plt.savefig("plot.png", dpi=300)
plt.show()
