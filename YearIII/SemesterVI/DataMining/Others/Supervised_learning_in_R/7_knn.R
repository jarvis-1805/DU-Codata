library(caret)

# Partition data into Train (80%) and Test (20%) sets
trainIndex <- createDataPartition(iris$Species, p=0.80, list=FALSE)
irisTrain <- iris[ trainIndex,]
irisTest  <- iris[-trainIndex,]


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
confusionMatrix(predictions, irisTest$Species)
