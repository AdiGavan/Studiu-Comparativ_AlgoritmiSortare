// "Copyright [2017], Gavan Adrian-George, 324CA"
class StructCustom {

  public:

    StructCustom() {

    }

    StructCustom(std::string text, int numar) {
      this->text = text;
      this->numar = numar;
    }

    std::string getText() {
      return text;
    }

    int getNumar() {
      return numar;
    }

    void setText(std::string text) {
      this->text = text;
    }

    void setNumar(int numar) {
      this->numar = numar;
    }

    void operator= (const StructCustom& elem)  {
      this->numar = elem.numar;
      this->text = elem.text;
    }

    bool operator< (const StructCustom& elem)  {
      return (compare(elem) < 0);
    }

    bool operator<= (const StructCustom& elem)  {
      return (compare(elem) <= 0);
    }

    bool operator> (const StructCustom& elem)  {
      return (compare(elem) > 0);
    }

    bool operator>= (const StructCustom& elem)  {
      return (compare(elem) >= 0);
    }

    bool operator== (const StructCustom& elem)  {
      return (compare(elem) == 0);
    }

    int compare (const StructCustom& elem) {

      if (numar < elem.numar) {
        return -1;
      } else if (numar > elem.numar) {
        return 1;
      } else if (text < elem.text) {
        return -1;
      } else if (text > elem.text) {
        return 1;
      }
      return 0;
    }

  private:
    std::string text;
    int numar;
};
