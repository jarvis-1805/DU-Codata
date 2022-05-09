library(caret)

# Partition data into Train (80%) and Test (20%) sets
trainIndex <- createDataPartition(iris$Species, p=0.80, list=FALSE)
irisTrain <- iris[ trainIndex,]
irisTest  <- iris[-trainIndex,]

# Train model using the Train partition
set.seed(101)
nnetFit <- train(Species~., irisTrain,
                 method = "nnet",
                 preProcess = "range",
                 maxit = 100)
nnetFit

# Predict using the Test partition
predictions <- predict(nnetFit, irisTest)
confusionMatrix(predictions, irisTest$Species)

