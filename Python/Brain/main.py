import array
import random

class MedianFilter:
    def __init__(self, S, N, D):
        self.S = S
        self.N = N
        self.D = D
        HistoryArray = [self.S][self.N]

def CreateLIDARScan():
    a = [random.uniform(-1000,1000) for i in range(random.randint(0,1000))]
    print"Printing LIDAR Scan of size ", len(a),":",
    return a

def PrintArray(Scan):
    for i in range(len(Scan)):
        print(Scan[i]),
    print "\n"

def RangeFilter(Scan):
    for i in range(len(Scan)):
        if Scan[i] < 0.03:
            Scan[i] = 0.03
        elif Scan[i] > 50.0:
            Scan[i] = 50.0
    print "Printing Filtered LIDAR Scan of size ", len(Scan),":",
    return Scan

#def Median(Scan):

#Base Scan
Scan = CreateLIDARScan()
PrintArray(Scan)
#Range Filter Scan
PrintArray(RangeFilter(Scan))
