#NAIVE BAYES CLASSIFIER

library("caret")
install.packages("klaR")
library("klaR")

data("iris")

# Partition data into Train (80%) and Test (20%) sets
trainIndex <- createDataPartition(iris$Species, p=0.80, list=FALSE)
trainIndex

irisTrain <- iris[ trainIndex,]
irisTrain

irisTest  <- iris[-trainIndex,]
irisTest

# Train model using the Train partition
set.seed(101)
nbModel = train(Species~.,irisTrain,method = 'nb',trControl=trainControl(method='cv',number=10))
nbModel

nbModel$finalModel

# Predict using the Test partition
predictions <- predict(nbModel, irisTest)
predictions

confusionMatrix(predictions, irisTest$Species)
