#include <iostream>
#include <string>
#include <stdlib.h>
#include <array>
#include <algorithm>
#include <vector>

#define MAX_TRIES 5
#define WORD_FOUND 1
#define WORD_NOT_FOUND 0
using namespace std;
int play_game(string word);
void print_help();


string words[] = {"abruptly" , "absurd" , "abyss" , "affix" , "askew" , "avenue" , "awkward" , "axiom" , "azure" , "bagpipes" , "bandwagon" , "banjo" , "bayou" , "beekeeper" , "bikini" , "blitz" , "blizzard" , "boggle" , "bookworm" , "boxcar" , "boxful" , "buckaroo" , "buffalo" , "buffoon" , "buxom" , "buzzard" , "buzzing" , "buzzwords" , "caliph" , "cobweb" , "cockiness" , "croquet" , "crypt" , "curacao" , "cycle" , "daiquiri" , "dirndl" , "disavow" , "dizzying" , "duplex" , "dwarves" , "embezzle" , "equip" , "espionage" , "euouae" , "exodus" , "faking" , "fishhook" , "fixable" , "fjord" , "flapjack" , "flopping" , "fluffiness" , "flyby" , "foxglove" , "frazzled" , "frizzled" , "fuchsia" , "funny" , "gabby" , "galaxy" , "galvanize" , "gazebo" , "giaour" , "gizmo" , "glowworm" , "glyph" , "gnarly" , "gnostic" , "gossip" , "grogginess" , "haiku" , "haphazard" , "hyphen" , "iatrogenic" , "icebox" , "injury" , "ivory" , "ivy" , "jackpot" , "jaundice" , "jawbreaker" , "jaywalk" , "jazziest" , "jazzy" , "jelly" , "jigsaw" , "jinx" , "jiujitsu" , "jockey" , "jogging" , "joking" , "jovial" , "joyful" , "juicy" , "jukebox" , "jumbo" , "kayak" , "kazoo" , "keyhole" , "khaki" , "kilobyte" , "kiosk" , "kitsch" , "kiwifruit" , "klutz" , "knapsack" , "larynx" , "lengths" , "lucky" , "luxury" , "lymph" , "marquis" , "matrix" , "megahertz" , "microwave" , "mnemonic" , "mystify" , "naphtha" , "nightclub" , "nowadays" , "numbskull" , "nymph" , "onyx" , "ovary" , "oxidize" , "oxygen" , "pajama" , "peekaboo" , "phlegm" , "pixel" , "pizazz" , "pneumonia" , "polka" , "pshaw" , "psyche" , "puppy" , "puzzling" , "quartz" , "queue" , "quips" , "quixotic" , "quiz" , "quizzes" , "quorum" , "razzmatazz" , "rhubarb" , "rhythm" , "rickshaw" , "schnapps" , "scratch" , "shiv" , "snazzy" , "sphinx" , "spritz" , "squawk" , "staff" , "strength" , "strengths" , "stretch" , "stronghold" , "stymied" , "subway" , "swivel" , "syndrome" , "thriftless" , "thumbscrew" , "topaz" , "transcript" , "transgress" , "transplant" , "triphthong" , "twelfth" , "twelfths" , "unknown" , "unworthy" , "unzip" , "uptown" , "vaporize" , "vixen" , "vodka" , "voodoo" , "vortex" , "voyeurism" , "walkway" , "waltz" , "wave" , "wavy" , "waxy" , "wellspring" , "wheezy" , "whiskey" , "whizzing" , "whomever" , "wimpy" , "witchcraft" , "wizard" , "woozy" , "wristwatch" , "wyvern" , "xylophone" , "yachtsman" , "yippee" , "yoked" , "youthful" , "yummy" , "zephyr" , "zigzag" , "zigzagging" , "zilch" , "zipper" , "zodiac" , "zombie"};

vector<string> puzzle;

int main()
{
    for(auto a : words)
    {
        puzzle.push_back(a);
    }

    print_help();
    exit(0);
    return 0;
}

void print_help()
{
    int user_operation;
    int result = 0;
    int i = 0;
    i = rand();
    string user_word ;
    user_word = puzzle[rand() % puzzle.size()];

    cout << "Enter operation" << endl;
    cout << "1. Play game" << endl;
    cout << "2. Exit " << endl;

    cin >> user_operation;

    if(user_operation == 1)
    {
        result = play_game(user_word);
        print_help();
    }
    else if(user_operation == 2)
    {
        return;
    }
    else
    {
        print_help();
    }
}
int play_game(string word)
{

    char ch;
    int counter = 0;
    int num_of_char_left = word.size();
    string s1;
    while(counter <= MAX_TRIES)
    {
        int found = 0;
        cout << "Guess a char" << endl;
        cin >> ch;
        cout << "words used : " << s1 << endl;
        if(!ispunct(ch) || !isdigit(ch))
        {
            if(s1.find(ch) != -1)
            {
                cout << "character already used" << endl;
                continue;
            }
            else
            {
                s1 += ch;
            }
            found = count(word.begin() , word.end() , ch);
            if(found != 0)
            {
                cout << "Char occurance detected" << endl;
                num_of_char_left -= found;
            }
            else
            {

                counter++;
            }

            if(num_of_char_left <= 0)
            {
                cout << "Hurray! word found" << endl;
                return WORD_FOUND; 
            }
        }
    }
    cout << "Maximum tries reached.Try again.." << endl;
    return WORD_NOT_FOUND;
}
