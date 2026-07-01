#include <string>
#include <vector>
#include <unordered_set>
#include <string_view>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        // הגנה מפני קלטים ריקים
        if (s.empty()) return true;
        if (wordDict.empty()) return false;

        // העברה ל-unordered_set לצורך שליפה ב-(1)O
        std::unordered_set<std::string_view> word_set(wordDict.begin(), wordDict.end());

        size_t n = s.length() + 1;
        // std::vector<bool> ממוטב ב-C++ ותופס רק ביט אחד לכל תא בזיכרון
        std::vector<bool> dp(n, false);
        dp[0] = true;

        // שימוש ב-string_view מאפשר לבצע חיתוכים (Slicing) בלי להקצות זיכרון חדש (Zero-allocation)
        std::string_view s_view(s);

        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                // אם העבר חוקי, נבדוק אם ה"זנב" הנוכחי נמצא במילון
                if (dp[j] && word_set.count(s_view.substr(j, i - j))) {
                    dp[i] = true;
                    break; // ה-break החכם שלך נשמר פה
                }
            }
        }

        return dp[s.length()];
    }
};