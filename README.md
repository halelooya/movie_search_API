# movie_search_API
## instruction to run this API:

1. Download BeatifulSoup and install.

2. Run "python crawl.py" in terminal:
```
  python crawl.py  
```
   This step will crawl the movie website and parse to get useful keywords for each movie (such as movie name, directors, actors, writers, year, genres, country and languages). Each keyword will be writen in lower case.<br/>
    Store the keywords into "raw_data.txt".
    
3. Run in terminal:
```
  g++ indexing.cpp
  ./a.out
```
  This step will indexing the keywords. Each keyword will be mapped with a list of movies which contain this keyword.<br/>
  Store the keywords map into "indexed_data.txt".
  
 4. Run in terminal:
 ```
  g++ search.cpp
  ./a.out
```
Loading indexed_data...<br/>
Loading done...<br/>
/-------------------------------------------/<br/>
/--------Search-top-1000-IMDB-movie---------/<br/>
/-------------------------------------------/<br/>
/Search by movie_name / directors / writers / <br/>
/actors / genres / year / country / language/<br/>
/-------------------------------------------/<br/>
<br/>
Please enter your keywords:(enter Q to quit)<br/>
2016 2012<br/>
Search result:<br/>
[]<br/>
/-------------------------------------------/<br/>
<br/>
Please enter your keywords:(enter Q to quit)<br/>
2012<br/>
Search result:<br/>
["Kahaani ","Ookami kodomo no Ame to Yuki ","The Dark Knight Rises ","Paan Singh Tomar ","The Avengers ","Django Unchained ","Moonrise Kingdom ","OMG ","Jagten ","The Perks of Being a Wallflower ","Skyfall ","The Hobbit: An Unexpected Journey ","Wreck-It Ralph ","Amour ","The Broken Circle Breakdown ","Vicky Donor ","Les Misérables ","Barfi! ","Gangs of Wasseypur ","End of Watch ","Argo ","Silver Linings Playbook ","English Vinglish ","Life of Pi ","The Impossible ","The Body "]<br/>
/-------------------------------------------/<br/>
<br/>
Please enter your keywords:(enter Q to quit)<br/>
spielberg hanks<br/>
Search result:<br/>
["Saving Private Ryan ","Catch Me If You Can ","Bridge of Spies "]<br/>
/-------------------------------------------/<br/>
<br/>
Please enter your keywords:(enter Q to quit)<br/>
Q<br/>
<br/>

This step will run the API, accept querys and return the search results.

