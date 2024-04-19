from matplotlib import pyplot as plt

donation_percentages = {    
    'Monetary': 40,    
    'Food Items': 30, 
    'Clothing': 20,
    'Books': 10
}

plt.pie(donation_percentages.values(), labels=donation_percentages, autopct='%1.1f%%')
plt.title("Donation Percentages at Community Center")
plt.show()