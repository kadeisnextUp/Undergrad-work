# -*- coding: utf-8 -*-
"""
Created on Sun Apr 27 10:41:30 2025

@author: Kaden Sawyer
"""

_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu"


import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

"""
Output should look something like this:
SciPy Linear Regression Solution 
 slope:  0.6325801874018306
 intercept: -0.02602000798390236        
 rvalue: 0.997749733854947
"""

"""
my results:
    SciPy Linear Regression Solution
     slope:  0.6320122157722157
     intercept:  0.226366006006117
     rvalue: 0.9999922573655418
"""
def simulate_balls_into_bins(N, trials=100):
    """simulate throwing N balls into N bins
    multiple times and return average non-empty bins"""
    nonEmptyCounts = []
    for _ in range(trials):
        bins = np.zeros(N)
        for _ in range(N):
            binIndex = np.random.randint(0, N)
            bins[binIndex] += 1
        nonEmpty = np.sum(bins > 0)
        nonEmptyCounts.append(nonEmpty)
    return np.mean(nonEmptyCounts)

def main():
    # simulation for N from 1 to 1000
    nValues = np.arange(1, 1001)
    results = []
    
    print("Running simulation...")
    for N in nValues:
        if N % 100 == 0:
            print(f"Processing N = {N}")
        avgNonEmpty = simulate_balls_into_bins(N)
        results.append(avgNonEmpty)
    
    
    x = np.array(nValues)
    y = np.array(results)
    
    # linear regression
    slope, intercept, r, p, std_err = stats.linregress(x, y)
    
    # print results
    print("\nSciPy Linear Regression Solution")
    print(" slope: ", slope)
    print(" intercept: ", intercept)
    print(" rvalue:", r)
    
    # plot results
    plt.figure(figsize=(10, 6))
    plt.plot(x, y, 'b.', label='Simulation Data')
    plt.plot(x, slope*x + intercept, 'r-', label=f'Linear Fit: y = {slope:.4f}x + {intercept:.4f}')
    plt.title('Balls into Bins Simulation (N=1 to 1000)')
    plt.xlabel('Number of Balls/Bins (N)')
    plt.ylabel('Average Non-empty Bins')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()