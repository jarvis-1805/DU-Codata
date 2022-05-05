#getting and setting the working directory
#ctrl+L to clear console
setwd("C:\\Users\\lenovo\\Desktop\\Rdatamining")
getwd()

#choose datafile from set directory
datafile <- file.choose()          #"./emp.txt"
empfile <- read.table(datafile,header=TRUE,sep=",")
empfile  #display entire table

edit(empfile)  #open editor to enter new values
#total records in dataframe
nrow(empfile)
#total columns in dataframe

ncol(empfile)
dim(empfile)  ##rows and cols

head(empfile,-5) #all but last 5 rows
tail(empfile)  #last 6 records
#displaying rows with valid values
AV<-na.omit(empfile)
#count valid rows
nrow(AV)

#looking for missing values in rows/columns
rowSums(is.na(empfile)) # Number of missing per row
colSums(is.na(empfile)) # Number of missing per column/variable
#logical vector indicating rows with missing val or not
complete.cases(empfile)

#return valid rows
empfile[complete.cases(empfile),]


#data scaling
install.packages("TH.data")
# bodyfat Data
data("bodyfat", package = "TH.data")
str(bodyfat)
dim(bodyfat)
d1<-bodyfat
head(d1)
km <- kmeans(d1, 3)

centers <- data.frame( size=km$size, km$centers)
round(centers, digits=2)

data1<-scale(d1)  #subtract mean and divide by std dev
head(data1)
head(d1)
km1 <- kmeans(data1, 3)

centers1 <- data.frame( size=km1$size, km1$centers)
round(centers1, digits=2)


data2<-scale(d1,scale=FALSE)  #subtract mean only
head(data2)
str(d1)

#data normalization
#install.packages("clusterSim")
library(clusterSim)

z1 <- data.Normalization(d1,type="n8",normalization="column")
z1
?data.Normalization
