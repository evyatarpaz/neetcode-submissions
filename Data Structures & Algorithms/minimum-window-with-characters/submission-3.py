from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""

        # מילון הדרישות של המחרוזת t
        required_chars = Counter(t)
        # מספר התווים הייחודיים ב-t שחייבים להופיע בחלון בכמות הנכונה
        required_unique_count = len(required_chars)

        # מילון שיעקוב אחרי התווים שנמצאים כרגע בתוך החלון של s
        window_counts = {}
        # כמה תווים ייחודיים מתוך t הגיעו למכסה הנדרשת שלהם בתוך החלון הנוכחי
        formed_unique_count = 0

        # משתנה לשמירת החלון המינימלי: (אורך_חלון, אינדקס_שמאל, אינדקס_ימין)
        # מאתחלים בערך אינסופי כדי שכל חלון חוקי ראשון יחליף אותו
        min_window_details = (float("inf"), 0, 0)

        left = 0
        # לולאת ה-for מזיזה את right אוטומטית, מה שמונע לחלוטין לולאות אינסופיות
        for right in range(len(s)):
            char = s[right]
            # 1. הוספת התו הנוכחי של right לחלון
            window_counts[char] = window_counts.get(char, 0) + 1

            # 2. אם התו הזה נדרש ב-t, והגענו בדיוק לכמות הנדרשת שלו בחלון - נסמן זאת
            if char in required_chars and window_counts[char] == required_chars[char]:
                formed_unique_count += 1

            # 3. שלב הכיווץ: כל עוד החלון הנוכחי חוקי ומכיל את כל התווים של t
            while left <= right and formed_unique_count == required_unique_count:
                # א) עדכון המינימום אם מצאנו חלון קטן יותר מהקודם
                current_window_len = right - left + 1
                if current_window_len < min_window_details[0]:
                    min_window_details = (current_window_len, left, right)

                # ב) אנחנו מנסים לצמצם את החלון משמאל - מוציאים את התו ב-left
                removed_char = s[left]
                window_counts[removed_char] -= 1

                # ג) אם התו שהוצאנו היה קריטי ל-t והספירה שלו ירדה מתחת למבוקש - החלון כבר לא חוקי
                if removed_char in required_chars and window_counts[removed_char] < required_chars[removed_char]:
                    formed_unique_count -= 1

                # ד) מקדמים את שמאל כדי להמשיך לנסות לצמצם באיטרציה הבאה של ה-while
                left += 1

        # החזרת התוצאה הסופית
        window_len, l, r = min_window_details
        return s[l : r + 1] if window_len != float("inf") else ""



        """
        Input: s = "OU ZODYX AZV", t = "XYZ"
        "ZODYX"
        "YXAZ"
        Output: "YXAZ"

        """