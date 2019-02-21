import array
import random

class MedianFilter:
    def __init__(self, S, N, D):
        self.S = S
        self.N = N
        self.D = D
        self.HistoryArray = [self.S][self.N]
    def Update(self, Scan):
        TotalHistory = len(self.HistoryArray) + 1
        for i in range(len(Scan)):
            if(TotalHistory > self.D - 1):
                del self.HistoryArray[i][-1]
                self.HistoryArray[i].append(Scan[i])
                self.HistoryArray[i].sort()
            else:
                self.HistoryArray[i].append(Scan[i])
                self.HistoryArray[i].sort()
            FilteredArray = [self.S][self.N]
        for j in range(TotalHistory - 1):
            if(TotalHistory % 2 == 0):
                    FilteredArray[j] = (self.HistoryArray[j][self.N / 2] + self.HistoryArray[j][(self.N / 2) - 1] * 0.5)
            else:
                FilteredArray[j] = self.HistoryArray[j][self.N / 2]
        return FilteredArray
Scan1 = [1, 2, 3, 4, 5]
Scan2 = [6, 7, 8, 9, 10]
Scan3 = [11, 12, 13, 14, 15]
d = MedianFilter(1, 1, 1)
d.Update(Scan1)
d.Update(Scan2)
for i in range(5):
    print d.Update(Scan3)[i]
'''
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
'''