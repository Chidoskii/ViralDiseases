import matplotlib.pyplot as plt
import numpy as np

ndays = 100
dt = 1                           #time step in days
beta = (1.0/3.0)                 #infection rate
gamma = (1.0/14.0)               #recovery rate  

S = np.zeros(ndays)             #susceptible population
I = np.zeros(ndays)             #infected population
R = np.zeros(ndays)             #removed population
t = np.arange(ndays)*dt

I[0] = 0.001                    #initial infective proportion
S[0] = 1.0 - I[0]               #initial susceptible proportion
R[0] = 0.0                      #initial removed proportion

for i in range(ndays-1):
    S[i+1] = S[i] - beta*(S[i]*I[i])*dt
    I[i+1] = I[i] + (beta*S[i]*I[i]-gamma*I[i])*dt
    R[i+1] = R[i] + (gamma*I[i])*dt
    
fig = plt.figure(1); fig.clf()
plt.plot(t,S,'r',lw=3, label='Suceptible')
plt.plot(t,I,'g',lw=3, label='Infected')
plt.plot(t,R,'b',lw=3, label='Recovered')
fig.legend(); plt.xlabel('Days'); plt.ylabel('Fraction of Population')