install.packages("caret")
library(caret)
trainIndex <- createDataPartition(iris$Species, p=0.80, list=FALSE)
irisTrain <- iris[ trainIndex,]
irisTest  <- iris[-trainIndex,]

# Train model using the Train partition
set.seed(101)
dtFit <- train(Species ~., method="J48", data=irisTrain,
               trControl = trainControl(method="cv"))

dtFit
dtFit$finalModel

# Predict using the Test partition
predictions <- predict(dtFit, irisTest)
confusionMatrix(predictions, irisTest$Species)
