#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

const std::vector<char> alphabet {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int init_game(char current_player); // function declaration

void invitation() {
  std::cout << R"(
      ⠀⠀⠀⠀⠀⠀  ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀
  ⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀
  ⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀
  ⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀
  ⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀
  ⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀
  ⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀Wellcome to the⢸⣿⣿⠀⠀
  ⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀Bulls and Cows ⢸⣿⣿⠀⠀
  ⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀
  ⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀
  ⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁
  Rules: computer or human trying to guess 4-digit number until get 4 bulls
  Bull - Guessed digit in right position
  Cow - Guessed only right digit, but not position)" << "\n\n";
}

// Collect chars from input stream for further validations
std::vector<char> collect_user_input() {
  char tmp;
  std::vector<char> input_data;
  
  std::cin >> std::noskipws;
  
  while (true) {
    std::cin >> tmp;
    
    if (tmp == '\n') break;
    input_data.push_back(tmp);
    
    if (!std::cin) throw std::runtime_error("Input stream error!");
    
  }
  
  std::cin >> std::skipws;
  return input_data;
}

char select_guesser() {
  std::cout << "Who will guess now? (press 'c' for computer and 'm' for me)\n";
  
  std::vector<char> user_input = collect_user_input();
  
  if (user_input.size() == 1) {
    switch(user_input[0]) {
      case 'c':
        return 'c';
    
      case 'm':
        return 'm';
        
      default:
        std::cerr << "Please, type in valid symbol :)\n\n";
        return select_guesser();
    }
  } else {
    std::cerr << "Insert only 1 valid symbol!\n\n";
    return select_guesser();
  }
}

// generate all possible sets 
std::vector<std::vector<char> > generate_all_sets(std::vector<char> alphabet) {
  
  std::vector<std::vector<char> > possible_sets {};
  
  int set_cardinality = alphabet.size();
  
  for (int i = 0; i < set_cardinality; ++i) {
    for (int j = 0; j < set_cardinality; ++j) {
      if (i != j)
      {
        for (int k = 0; k < set_cardinality; ++k) {
          if (i != k && j != k)
          {
            for (int l = 0; l < set_cardinality; ++l) {
              if (i != l && j != l && k != l)
              {
                std::vector<char> set {};
                set.push_back(alphabet[i]);
                set.push_back(alphabet[j]);
                set.push_back(alphabet[k]);
                set.push_back(alphabet[l]);
                possible_sets.push_back(set);
              }
            }
          }
        }
      }
    }
  }
  
  return possible_sets;
}

std::vector<char> generate_quiz(int quiz_size, std::vector<char> alphabet) {
  
  if (quiz_size > alphabet.size()) {
    throw std::runtime_error("Error: quiz size is greater than possible set of values");
  }
  
  // set random seed
  srand(static_cast<size_t>(time(0)));
  
  std::vector<char> current_quiz {};

  while (current_quiz.size() != 4) {
    //get random index of set value
    int index = rand() % alphabet.size();
    
    current_quiz.push_back(alphabet[index]);
    alphabet.erase(alphabet.begin() + index);
    
  }
  
  for (int i = 0; i < current_quiz.size(); ++i) {
    std::cout << current_quiz[i];
  }
  
  return current_quiz;
}

std::vector<char> collect_user_guess() {
    
    std::cout << "Guess the number: " << "\n" << ">";
    
    std::vector<char> user_input = collect_user_input();
    
    // validate input vector size
    if (user_input.size() != 4) {
      std::cerr << "Allert! Insert 4-digit sequence!\n\n";
      return collect_user_guess();
    }
    
    // all digits must be distinct
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        if (user_input[i] == user_input[j]) {
          std::cerr << "All digits must be distinct!\n\n";
          return collect_user_guess();
        }
      }
    }
    
    return user_input;
}

class Game {
  public:
    int bulls = 0;
    int cows = 0;
};

int count_bulls(std::vector<char> guessed_sequence, std::vector<char> user_guess) {
  int counter = 0;
  
  for (int i = 0; i < guessed_sequence.size(); ++i) {
    if (guessed_sequence[i] == user_guess[i]) {
      ++counter;
    }
  }
  
  return counter;
}

int count_cows(std::vector<char> guessed_sequence, std::vector<char> user_guess) {
  int counter = 0;
  
  int n = guessed_sequence.size();
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (guessed_sequence[i] == user_guess[j] && i != j) {
        ++counter;
      }
    }
  }
  
  return counter;
}


int human_guesser() {
  
  Game game_state;
  
  std::vector<char> guessed_sequence = generate_quiz(4, alphabet);
  
  while (game_state.bulls != 4) {
    std::vector<char> user_guess = collect_user_guess();
    
    game_state.bulls = count_bulls(guessed_sequence, user_guess);
    game_state.cows = count_cows(guessed_sequence, user_guess);
    
    std::cout << "Count of bulls: " << game_state.bulls << "\n";
    std::cout << "Count of cows: " << game_state.cows << "\n\n";
  
  }
  
  std::cout << "Game over! In good sense, of course :) You win!\n\n";
  
  return init_game(select_guesser());
}

// collect user feedback

// class Feedback {
//   public:
//     std::vector<char> initial_prediction = {};
//     int bulls = 0;
//     int cows = 0;
// }

Game collect_user_feedback(std::vector<char> initial_prediction) {
  
  Game feedback;
  
  std::cout << "Here my prediction: ";
  for (char x : initial_prediction) {
    std::cout << x;
  }
  
  std::cout << "\nHow many bulls?\n";
  std::cin >> feedback.bulls;
  
  std::cout << "How many cows?\n";
  std::cin >> feedback.cows;
  
  return feedback;
}

// number compution algorithm
std::vector<char> find_number(std::vector<char> predicted_number, 
                              int bulls_found, 
                              int cows_found, 
                              std::vector<std::vector<char> >& current_sieve) {
                              
  if (current_sieve.size() == 1) {
    return current_sieve[0];
  } else if (bulls_found == 4) {
    return predicted_number;
  } else {
    // filter elements
    for (int i = current_sieve.size() - 1; i != 0; --i) {
      
      
      // check the criteria
      int current_cows = count_cows(predicted_number, current_sieve[i]);
      int current_bulls = count_bulls(predicted_number, current_sieve[i]);
      //std::cout << "Index " << i << "contains " << current_bulls << " bulls and " << current_cows << " cows";
      
      if (current_bulls != bulls_found) {
        current_sieve.erase(current_sieve.begin() + i);
      } else if (current_cows != cows_found) {
        current_sieve.erase(current_sieve.begin() + i);
      }
      
    }
    
    // make a function of this
    std::vector<char> initial_prediction = current_sieve[current_sieve.size() - 1];
    Game user_feedback = collect_user_feedback(initial_prediction);
    
   //std::cout << "размер массива " << current_sieve.size();
   return find_number(initial_prediction, user_feedback.bulls, user_feedback.cows, current_sieve);
  }
}

int machine_guesser() {
  
  Game game_state;
  
  std::cout << "Hope, you have picked a number\n\n";
  
  // sieve filtering
  std::vector<std::vector<char> > sieve = generate_all_sets(alphabet);
  
  std::vector<char> initial_prediction = sieve[sieve.size() - 1];
  
  Game user_feedback = collect_user_feedback(initial_prediction);
  
  std::vector<char> exact_guess = find_number(initial_prediction, user_feedback.bulls, user_feedback.cows, sieve);
  
  std::cout << "Here is your secret number:\n";
  for (char x : exact_guess) {
    std::cout << x;
  }
  std::cout << std::endl;
  
  return init_game(select_guesser());
}

int init_game(char current_player) {
    if (current_player == 'c') {
      return machine_guesser();
    } else {
      return human_guesser();
    }
}

int main() {
  try {
    
    invitation();
    char current_player = select_guesser();
    init_game(current_player);
    
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch(...) {
    std::cerr << "Oops, something went wrong...\n";
    return 2;
  }
  
}
