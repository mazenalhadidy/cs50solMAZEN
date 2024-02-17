#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool هلحروف(string a);
bool هلتكرار(string b);

int main(int argc, string argv[])
{
    //هنا أحدد له أنه يجب أن يكون سترينغ واحد فقط المدخل بعد البرنامج
    //وكذلك يجب أن يكون هذا السترينغ مكون من 26 حرفا، وأن يكون كله حروف، وألا يكون فيه تكرار
    if ((argc == 2) && (strlen(argv[1]) == 26) && (هلحروف(argv[1]) == true) && (هلتكرار(argv[1]) == false))

    {
        string x = get_string("من فضلك، اكتب الكلمة المستشفرة: ");
        string z = argv[1];
        printf("ciphertext: ");

        //هنا أمر على كل حرف من الكلمة المطلوب تشفيرها
        for (int i = 0; i < strlen(x); i++)

        {
            //هنا أحدد ألا يجري عملية التشفير إلا على الحروف لا على الرموز ولا الأرقام، و إلا يطبعهم كما هم في إلس
            if (isalpha(x[i]))

            {
                //هنا أقول له إن كان الحرف المستشفر حرفا كبيرا فسأطرح من قيمة الأسكي الخاصة به 65
                if (isupper(x[i]))

                {
                    int index = (int) x[i] - 65;

                    //في شرط إف هذا أحدد هل حرف مفتاح الشيفرة كبير أو صغير، إن كان كبيرا يطبع كما هو، و إن كان صغيرا يكبر
                    if (isupper(z[index]))
                    {
                        printf("%c", z[index]);
                    }
                    else
                    {
                        printf("%c", toupper(z[index]));
                    }
                }

                //إلس هذه معناها أن الحرف في الكلمة المستشفرة صغير لذلك رقم الدليل سيكون مختلفا
                else

                {
                    int index = (int) x[i] - 97;

                    //هنا أقول له إن كان حرف مفتاح الشيفرة كبيرا يصغره، و إن كان صغيرا يطبعه كما هو
                    if (isupper(z[index]))

                    {
                        printf("%c", tolower(z[index]));
                    }
                    else
                    {
                        printf("%c", z[index]);
                    }
                }
            }
            //هنا كما ذكرت في الأعلى، أنه إن وجد في الكلمة المستشفرة أي شيئ غير الحرف يطبعه كما هو
            else

            {
                printf("%c", x[i]);
            }
        }

        printf("\n");
        printf("plaintext: %s\n", x);
        return 0;
    }

    //---------------------------------
    //في هذه الحالات أحدد أن لا يدخل المستخدم إلا كلمة واحدة بعد البرنامج وهو مفتاح الشيفرة
    else if (argc < 2)

    {
        printf("من فضلك اكتب مفتاح الشيفرة\n");

        //يجب كتابة قيمة الإرجاع هنا على أنها أي رقم غير الصفر، لكي يعلم البرنامج أن القيمة المدخلة تسبب عطلا
        return 1;

    }
    else if (argc > 2)
    {
        printf("من فضلك لا تكتب أي شيء بعد مفتاح الشيفرة\n");
        return 1;
    }
    else if (argc == 2)
    {
        printf("مفتاح غير صالح\n");
        return 1;
    }
}

//--------------------------------------------------------------------------------------

bool هلحروف(string a)
{
    //انتبه أنك لا تستطيع أن تضع أمر إرجاع القيمة داخل دورة فور، إنما يجب أن تنشئ متغير و ترجعه خارج الدورة
    bool x = true;

    for (int i = 0; i < strlen(a); i++)
    {
        // هنا أقول له أن يمر على كل حرف من الكلمة المدخلة، إن وجد أن أي حرف منها ليس حرفا ألفبائيا سيحول (إكس) إلى خطأ
        //ثم حدثت العداد ليصل لآخر قيمة ليخرج من دورة فور
        if (isalpha(a[i]) == false)

        {
            x = false;
            i = strlen(a);
        }
    }
    return x;
}

//----------------------------------------------------------------------------
bool هلتكرار(string b)
{
    bool m = false;

    //دورة فور هذه مسؤولة أن تمر على كل حرف من حروف السلسال المدخل
    for (int i = 0; i < strlen(b); i++)

    {
        //هنا كأني أقول له، عند أول حرف من السلسال ادخل في دورة فور أخرى
        //هذه الدورة تقارن بين الحرف المعلم من دورة فور الأخرى لتقارن بينه و بين سائر حروف السلسال
        //إن وجدت أن الحرف المعلم يساوي الحرف المقارن تجعل المتغير (إم) صواب
        //ثم حدثت عدادي الدورتين لأقصى قيمة حتى يخرج من الدورتين
        for (int j = i + 1; j < strlen(b); j++)

        {
            if (b[i] == b[j])
            {
                m = true;
                i = strlen(b);
                j = strlen(b);
            }
        }
    }
    return m;
}