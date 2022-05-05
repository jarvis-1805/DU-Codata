R.version  #r version running

search()        # Shows the loaded packages

getOption("defaultPackages")

library()       # Shows the installed packages

#install.packages("ggplot2")
#install.packages("tidyr")

library(ggplot2)
search()

library("tidyr")
search()

#install.packages(c("tidyr", "devtools")) #tidyr for data handling

getwd()  #name of the working directory

dir()  # show files in the working directory

#to change working directory
#getting and setting the working directory
setwd("C:\\Users\\lenovo\\Desktop\\Rdatamining")

getwd()


#Kmeans clustering
data(iris)

#to get structure of data
str(iris)

iris2 <- iris
View(iris2)
str(iris2)

iris2$Species <- NULL #not to use species field
str(iris2)

km <- kmeans(iris2, 3)  # 3 clusters
km

?kmeans

km$size  #size of each cluster

km$centers

km$cluster

km$iter  #number of iterations used

iris2$cluster <- factor(km$cluster) #adding cluster label with each point
View(iris2)

km$withinss  #each cluster Sum of square error

#visulaizing clusters
I=iris2[c(1,2,5)]
View(I)  #data to plot

centers <- data.frame(cluster=factor(1:3), km$centers)
centers

ggplot(data=I, aes(x=Sepal.Length, y=Sepal.Width, color=cluster, shape=cluster)) +
  geom_point(alpha=.3)+
  geom_point(data=centers, aes(x=Sepal.Length, y=Sepal.Width), size=3, stroke=2)

#plotting mean of each variable within each cluster
centers=km$centers
t(centers)

centers <- as.data.frame(t(centers))
names(centers) <- paste("Cluster", 1:3)
centers

centers$Symbol <- row.names(centers)
centers$Symbol

centers <- gather(centers, "Cluster", "Mean", -Symbol)
centers$Color = centers$Mean > 0
ggplot(centers, aes(x=Symbol, y=Mean, fill=Color)) +
  geom_bar(stat='identity', position = "identity", width=.75) +
  facet_grid(Cluster ~ ., scales='free_y')

#comparing clusters with actual class species
table(iris$Species, km$cluster)

#other parameters setting
km1 <- kmeans(iris2, 2,5) #adding number of iteration
km1

table(iris$Species, km1$cluster) 
#may create confusion matrix

