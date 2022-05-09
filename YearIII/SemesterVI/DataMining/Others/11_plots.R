# Load dataset iris
data(iris)
TrainData <- iris[,1:4]  
View(TrainData)

TrainClasses <- iris[,5]
View(TrainClasses)

#Scatterplot matrix
featurePlot(x=TrainData, y=TrainClasses, plot="box")
featurePlot(x=TrainData, y=TrainClasses, plot="pairs")
featurePlot(x=TrainData, y=TrainClasses, plot="strip")
featurePlot(x=TrainData, y=TrainClasses, plot="density")  #Density Plot

install.packages("ellipse")
library(ellipse)

featurePlot(x=TrainData, y=TrainClasses, plot="ellipse")

