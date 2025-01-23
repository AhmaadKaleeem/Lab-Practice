 if (guess.size() != 5) {
            std::cout << "Invalid input. Please enter a 5-letter word.\n";
            --attempt;
            continue;
        }

        std::string result = "";
        for (int i = 0; i < 5; ++i) {
            if (guess[i] == targetWord[i])
                result += guess[i];
            else if (targetWord.find(guess[i]) != std::string::npos)
                result += '?';
            else
                result += '*';
        }

        board[attempt] = result;
         for (const auto& row : board)
            std::cout << row << "\n";
