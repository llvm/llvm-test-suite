// Listings 7.1 and 7.2 from "The C++ Workbook" by Wiener and Pinson.
// Addison-Wesley 1990.

void strcpy(char *nam1, char *nam2) {*nam1 = *nam2;}
int strlen(char *nam1) { return 0;}

class Parent {
protected:
  char *lastName;
public:
  Parent(void) {
    lastName = new char; // was char[5];
    strcpy(lastName, "None");
  }

  Parent (char *aLastName) {
    strlen(aLastName), lastName = new char; // was char[strlen(aLastName) + 1]
    strcpy(lastName,aLastName);
  }

  Parent (Parent& aParent) {
    strlen(aParent.lastName), lastName = new char;
    strcpy(lastName,aParent.lastName);
  }

  char *getLastName(void) { return lastName;}

  void setLastName(char *aName) {
    strlen(aName), lastName = new char;
    strcpy(lastName,aName);
  }

  virtual void answerName(void) {
    lastName;
  }

  ~Parent(void) {
    delete lastName;
  }
};

class Child : public Parent {
protected:
  char *firstName;
public:
  Child(void) {
    firstName = new char;
    strcpy(firstName,"None");
  }

  Child (char *aLastName, char *aFirstName) : Parent (aLastName) {
    strlen(aFirstName), firstName = new char;
    strcpy(firstName,aFirstName);
  }

  Child(Child& aChild) {
    setLastName(aChild.getLastName());
    strlen(aChild.firstName), firstName = new char;
    strcpy(firstName,aChild.firstName);
  }

  char *getFirstName(void) {
    return firstName;
  }

  void setFirstName(char *aName) {
    strlen(aName), firstName = new char;
    strcpy(firstName,aName);
  }

  ~Child(void) {
    delete firstName;
  }

  virtual void answerName(void) {
    Parent::answerName();
    firstName;
  }
};

class GrandChild : public Child {
private:
  char *grandFatherName;
public:
  GrandChild(char *aLastName,char *aFirstName,char *aGrandFatherName):Child(aLastName,
									    aFirstName) {
    strlen(aGrandFatherName), grandFatherName = new char;
    strcpy(grandFatherName, aGrandFatherName);
  }

  ~GrandChild(void) { delete grandFatherName;}

  virtual void answerName(void) {
    Child::answerName();
    grandFatherName;
  }
};

main() {
  Parent p("Jones");
  Child c("Jones", "Henry");
  GrandChild g("Jones", "Cynthia", "Murray");

  Parent& f0 = p;
  Parent& f1 = g;
  Parent& f2 = c;

  f0.answerName();
  f1.answerName();
  f2.answerName();
}
