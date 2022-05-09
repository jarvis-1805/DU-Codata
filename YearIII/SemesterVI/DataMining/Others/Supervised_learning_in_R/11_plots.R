# Load dataset iris
data(iris)
TrainData <- iris[,1:4]  
TrainClasses <- iris[,5]
#Scatterplot matrix
featurePlot(x=TrainData, y=TrainClasses, plot="ellipse")

#Density plot
featurePlot(x=TrainData, y=TrainClasses, plot="density", scales=scales)
