from matplotlib import pyplot as plt

monthly_temperatures = [5, 7, 9, 12, 15, 17, 16, 14, 10, 8, 6, 5, 4, 6, 8, 11, 13, 15, 18, 20, 22, 23, 21, 19, 17, 15, 12, 10, 8]
days_of_month = [i for i in range(1, 30)]

x_ticks = [i for i in range(1, 30)]
y_ticks = [i for i in range(min(monthly_temperatures), max(monthly_temperatures) + 1)]

plt.figure(figsize=(10, 6))
plt.plot(days_of_month, monthly_temperatures)

plt.title("Monthly Average Temperatures")

plt.xticks(x_ticks)
plt.xlabel("Day of Month")

plt.yticks(y_ticks)
plt.ylabel("Average Temperature (°C)")

plt.show()
