class File {
private:
  // Iterates through all the lines in file and call the given callback on each
  // line.
  

public:
  static bool iterate_file(std::string, std::function<void(const std::string &)>);
  static std::vector<std::string> read_to_vector(std::string &);
  static std::vector<std::string> read_to_vector(const char *);
  static std::string read(std::string &);
  static std::string read(const char *);
  static bool exists(const string&);
};


class Bash{
  public:
    static std::string run(std::string &);
    static std::string run(const char *);
};

