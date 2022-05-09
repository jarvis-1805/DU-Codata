library(caret)

View(iris) #original dataset
# Partition data into Train (80%) and Test (20%) sets
trainIndex <- createDataPartition(iris$Species, p=0.80, list=FALSE)
View(trainIndex)  #120 observations

irisTrain <- iris[ trainIndex,]
View(irisTrain)

irisTest  <- iris[-trainIndex,]
View(irisTest)

#Train knn using cross validation
set.seed(101)
knnFit1 <- train(Species~., irisTrain,
                 method = "knn",
                 preProcess = c("center", "scale"),
                 trControl = trainControl(method = "cv", number =10))


knnFit1

plot(knnFit1)

ggplot(knnFit1)

predictions <- predict(knnFit1, irisTest)
View(predictions)

confusionMatrix(predictions, irisTest$Species)
