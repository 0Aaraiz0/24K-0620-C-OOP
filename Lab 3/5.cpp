#include <iostream>
using namespace std;

class MusicPlayer {
private:
    string playList[100];
    int songcount;

public:
    MusicPlayer(string a, string b, string c, int k) {
        playList[0] = a;
        playList[1] = b;
        playList[2] = c;
        songcount = k;
    }

    void addSong() {
        if (songcount >= 100) {
            cout << "Playlist is full. Cannot add more songs." << endl;
            return;
        }

        cout << "Enter song to add: ";
        cin >> playList[songcount]; 
        songcount++;
        cout << "Song added successfully!" << endl;
    }

    void removeSong() {
        string rsong;
        cout << "Enter song to remove: ";
        cin >> rsong;

        for (int i = 0; i < songcount; i++) {
            if (rsong == playList[i]) {
                for (int j = i; j < songcount - 1; j++) {
                    playList[j] = playList[j + 1];
                }
                songcount--; 
                cout << "Song removed successfully!" << endl;
                return;
            }
        }
        cout << "Invalid song! Not found in playlist." << endl;
    }

    void playSong() {
        string psong;
        cout << "Enter song to play: ";
        cin >> psong;

        for (int i = 0; i < songcount; i++) {
            if (playList[i] == psong) {
                cout << playList[i] << " is currently playing." << endl;
                return;
            }
        }
        cout << "Invalid song! Not found in playlist." << endl;
    }

    void displayPlayList() {
        if (songcount == 0) {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "Your Playlist:" << endl;
        for (int i = 0; i < songcount; i++) {
            cout << i + 1 << ". " << playList[i] << endl;
        }
    }
};

int main() {
    MusicPlayer MP("Money", "Black", "Hispanic", 3);

    int ch;
    while (true) {
        cout << "\n1. Add Song" << endl;
        cout << "2. Remove Song" << endl;
        cout << "3. Play Song" << endl;
        cout << "4. Display Songs" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                MP.addSong();
                break;
            case 2:
                MP.removeSong();
                break;
            case 3:
                MP.playSong();
                break;
            case 4:
                MP.displayPlayList();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    }
}
