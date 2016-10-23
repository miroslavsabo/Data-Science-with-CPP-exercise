setwd("~/Documents/TOP/MY CPP PACKAGES/parsing-exercise/")

n <- 10

temperature <- as.character(rnorm(n)) 

set.seed(1234)
station <- sample(c("aaaaaaa", "b", "c"), n, replace = TRUE) 

data <- c(
  c("efef", "", "er;;;;"),
  c(paste(station, temperature, sep = ";")),
  c("efrfr;fr;rfrgfr;gr", "", "a", "-0.1;a")
  )

writeLines(data, "data/stations.csv")
  