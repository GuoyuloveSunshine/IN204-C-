// class enumerate_characters
// {
// private:
//   int mPosition;
//   int mNumberOfCharacters;
//   const char* mString;
// public:
//   enumerate_characters(const char* aString, int theNumberOfCharacters):
//       mString(aString), mNumberOfCharacters(theNumberOfCharacters) {}
 
//   int next()
//   {
//       return mPosition < mNumberOfCharacters ? 
//         (int)mString[mPosition++] : -1;
//   }
//   void reset()
//   {
//       mPosition = 0;
//   }
// }

// ce qui veut que l'ensemble des champs et méthodes présents dans la classe enumerate_characters 
// sont présents dans la classe bidi_enumerate_characters. Attention, les champs ou méthodes privées sont présentes 
// mais ne sont pas accessibles. Ici, nous avons besoin des champs mNumberOfCharacters et mString dans la classe dérivée, 
// c'est pour cela que nous avons modifié la classe de base enumerate_characters pour les rendre toujours inaccessibles en 
// dehors de la classe mais accessible dans les classes derivées en les déclarant comme proctected :


class enumerate_characters
{
private:
  int mPosition;
protected:
  int mNumberOfCharacters;
  const char* mString;
public:
    enumerate_characters(const char* aString, int theNumberOfCharacters):
        mString(aString), mNumberOfCharacters(theNumberOfCharacters) {}
 
    int next(){
      return mPosition < mNumberOfCharacters ? 
        (int)mString[mPosition++] : -1;
    }
    void reset(){
      mPosition = 0;
    }
}
 
class bidi_enumerate_characters: enumerate_characters
{
private:
    int mReversePosition;
public:
    bidi_enumerate_characters(const char* aString, int theNumberOfCharacters):
        enumerate_characters(aString, theNumberOfCharacters), mReversePosition(theNumberOfCharacters) {}
 
    int previous(){
      return mReversePosition >= 0 ? 
        (int)mString[mPosition++] : -1;
    }
    void reset(){
        mReversePosition= mNumberOfCharacters;
        enumerate_characters()::reset();
    }
}