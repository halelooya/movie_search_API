# movie_search_API
## instruction to run this API:

1. Download BeatifulSoup and install.

2. Run "python crawl.py" in terminal:
```
  python crawl.py  
```
   This step will crawl the movie website and parse to get useful keywords for each movie (such as movie name, directors, actors, writers, year, genres, country and languages). Each keyword will be writen in lower case.
    Store the keywords into "raw_data.txt".
    
3. Run in terminal:
```
  g++ indexing.cpp
  ./a.out
```
  This step will indexing the keywords. Each keyword will be mapped with a list of movies which contain this keyword.
  Store the keywords map into "indexed_data.txt".
  
 4. Run in terminal:
 ```
  g++ search.cpp
  ./a.out
```
Loading indexed_data...
Loading done...
/-------------------------------------------/
/--------Search-top-1000-IMDB-movie---------/
/-------------------------------------------/
/Search by movie_name / directors / writers / 
/actors / genres / year / country / language/
/-------------------------------------------/

Please enter your keywords:(enter Q to quit)
2016 2012
Search result:
[]
/-------------------------------------------/

Please enter your keywords:(enter Q to quit)
2012
Search result:
["Kahaani ","Ookami kodomo no Ame to Yuki ","The Dark Knight Rises ","Paan Singh Tomar ","The Avengers ","Django Unchained ","Moonrise Kingdom ","OMG ","Jagten ","The Perks of Being a Wallflower ","Skyfall ","The Hobbit: An Unexpected Journey ","Wreck-It Ralph ","Amour ","The Broken Circle Breakdown ","Vicky Donor ","Les Misérables ","Barfi! ","Gangs of Wasseypur ","End of Watch ","Argo ","Silver Linings Playbook ","English Vinglish ","Life of Pi ","The Impossible ","The Body "]
/-------------------------------------------/

Please enter your keywords:(enter Q to quit)
spielberg hanks
Search result:
["Saving Private Ryan ","Catch Me If You Can ","Bridge of Spies "]
/-------------------------------------------/

Please enter your keywords:(enter Q to quit)
Q


This step will run the API, accept querys and return the search results.

