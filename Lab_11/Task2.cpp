#include <iostream>

using namespace std;

class Artist
{
    string name;

public:
    Artist(string name) : name(name) {}

    virtual string getType() = 0;
};

class Musician : public Artist
{

public:
    Musician(string name) : Artist(name) {}

    string getType()
    {
        return "Musician";
    }
};

class Band : public Artist
{
    int numOfMusicians;
    Musician **musicians;

public:
    Band(string name, Musician *musician1, Musician *musician2) : Artist(name), numOfMusicians(0)
    {
        // Adding the minimum needed two musicians
        addMusician(musician1);
        addMusician(musician2);
    }

    string getType()
    {
        return "Band";
    }

    void addMusician(Musician *musician)
    {
        Musician **newMusicians = new Musician *[numOfMusicians + 1];

        // Copy old data
        for (int i = 0; i < numOfMusicians; i++)
        {
            newMusicians[i] = musicians[i];
        }

        // Add new data
        newMusicians[numOfMusicians] = musician;

        // Delete old data
        if (numOfMusicians > 0)
        {
            delete[] musicians;
        }

        // Replace old data
        musicians = newMusicians;

        // Increment number of musicians
        numOfMusicians++;
    }
};

class Song
{
    Artist *performer, *writer;

public:
    Song(Artist *performer,
         Artist *writer)
        : performer(performer),
          writer(writer) {}

    void setPerformer(Artist *performer)
    {
        this->performer = performer;
    }

    Artist *getPerformer()
    {
        return this->performer;
    }

    void setWriter(Artist *writer)
    {
        this->writer = writer;
    }

    Artist *getWriter()
    {
        return this->writer;
    }
};

class Track
{
    Song *song;

public:
    Track(Song *song) : song(song) {}
};

class Album
{
    string name;
    int numOfTracks;
    Track **tracks;

public:
    Album(string name) : name(name), numOfTracks(0) {}

    void addTrack(Track *track)
    {
        Track **newTracks = new Track *[numOfTracks + 1];

        // Copy old data
        for (int i = 0; i < numOfTracks; i++)
        {
            newTracks[i] = tracks[i];
        }

        // Add new data
        newTracks[numOfTracks] = track;

        // Delete old data
        if (numOfTracks > 0)
        {
            delete[] tracks;
        }

        // Replace old data
        tracks = newTracks;

        // Increment number of musicians
        numOfTracks++;
    }
};

int main()
{
    Musician musician1("Sarim");
    Musician musician2("Someone");
    Musician musician3("Someone else");
    Musician musician4("Someone else too");

    cout << musician1.getType() << endl;

    Band band("a band", &musician1, &musician2);
    band.addMusician(&musician1);
    cout << band.getType() << endl;

    Song song1(&musician1, &musician2);
    Song song2(&musician1, &musician2);
    Song song3(&musician1, &musician2);

    Track track1(&song1);
    Track track2(&song2);
    Track track3(&song3);

    Album album("an album");
    album.addTrack(&track1);
    album.addTrack(&track2);
    album.addTrack(&track3);
}