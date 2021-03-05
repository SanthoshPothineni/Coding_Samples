import csv
inFile = open("input.txt", "r")
outFile = open("output.txt", "w")
temp = 0
s = 0
LowestAvg = 2000.0
HighestAvg = 0.0


My_reader = csv.reader(inFile, delimiter = ',')

outFile.write("Tampa Average Temperatures in January" + '\n')
outFile.write("Decade" + '\t' + "Average Temp" + '\n')
for line in My_reader:
    date = int(line[0])
    temp += float(line[1])
    s += 1
    if s == 10:
        avgtemp = temp / 10
        if avgtemp < LowestAvg:
            LowestAvg = avgtemp
        if avgtemp > HighestAvg:
            HighestAvg = avgtemp    
        s = 0
        temp = 0
        date = (date - 901)/100
        output = (str(round(date)) + "'s" + '\t' + str(round(avgtemp, 2)) + '\n')
        outFile.write(output)
    

output = ('\n' + "Highest Decade Average Temp: " + str(round(HighestAvg, 2)) + '\n')
outFile.write(output)

output = ("Lowest Decade Average Temp: " + str(round(LowestAvg, 2)) + '\n')
outFile.write(output)
        
        

inFile.close()
outFile.close()
