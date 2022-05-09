installed.packages()  # to see installed packages
install.packages() # to install all the packages

#________________ BUILT IN DATASETS_______________________
# to see all the datasets in all the installed packages 
data()

# to see all datasets in a package
data(package = "survival")

#to include all installed packages
data(package = .packages(TRUE))

install.packages("faraway")
# to access a selected dataset from a package
data("nepali", package = "faraway")   #data set taken form nepali children

nepali  # to view nepali dataset

data("worldcup", package = "faraway") # 2010 worldcup dataset

data("iris", package = "datasets")   #data set taken from iris 

#___________________READING FROM & WRITING TO EXTERNAL FILE_____________________

install.packages("readr")
library(readr)
document_graph_properties <- read.csv("~/Desktop/Results_Document_classification/Results_graph_prop/alll_tech_non-tech_graph_correct.csv", 
                             header=TRUE,nrows = 20, fill = TRUE, skipNul = TRUE)
View(document_graph_properties)

# skipping first Few Rows
document_graph_properties_2 <- read.csv("~/Desktop/Results_Document_classification/Results_graph_prop/alll_tech_non-tech_graph_correct.csv", 
                                        header = FALSE,skip = 5,nrows = 20, 
                                        fill = TRUE, 
                                        skipNul = TRUE
                                        )
View(document_graph_properties_2)


#writing the dataset to an output file

write.csv(document_graph_properties_2, "~/Desktop/Workshop_R/output_csv.csv")


#___________________________SOME USEFUL FUNCTIONS__________________________


# to display dataset structure
str(worldcup)
str(iris)

# to load first n rows
head(nepali, 3)

# to load last n rows
tail(nepali, 5)


#access a column
worldcup$Team
worldcup$Position

worldcup[,"Team"]

#data set function
worldcup[1,]  

worldcup[1,4]

worldcup[c(1,3),]  

worldcup[c(1,4),c("Position","Shots","Tackles")]

#To know about number of levels (ONLY FOR NOMINAL COLUMN, ELSE RETURNS NULL)

levels(worldcup$Position)

#No. of rows & cols

nrow(worldcup)
ncol(worldcup)

#_______________________ACCESSING WEB DATA THROUGH API__________________________

#Accessing Stock tick for Microsoft
install.packages("quantmod")
library(quantmod)
#If you are using a version before 0.5.0 then set this option 
#or pass auto.assign = FALSE to getSymbols.
options(getSymbols.auto.assign = FALSE)
microsoft <- getSymbols("MSFT")
head(microsoft, 5)

# Scraping web pages

salary_url <- "http://www.justinmrao.com/salary_data.csv" # football player salary data
local_copy <- "my local copy.csv"
download.file(salary_url, local_copy)
salary_data <- read.csv(local_copy)
head(salary_data)

# Scrapping html page
library(RCurl)
library(XML)

time_url <- "http://tycho.usno.navy.mil/cgi-bin/timer.pl"
time_page <- getURL(time_url)
cat(time_page)


time_doc <- htmlParse(time_page)
pre <- xpathSApply(time_doc, "//pre")[[1]]
values <- strsplit(xmlValue(pre), "\n")[[1]][-1]
strsplit(values, "\t+")

