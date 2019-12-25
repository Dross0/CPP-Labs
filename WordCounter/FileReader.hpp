#pragma once
#include<string>
#include<fstream>

class FileReader {
public:
    explicit FileReader(const std::string &path) : path_(path), is_open_(false)
    {
        file_.open(path);
        is_open_ = file_.is_open();
    }

    ~FileReader(){
        file_.close();
    }

    bool getLine(std::string & str) {
        if (file_.eof())
            return false;
        getline(file_, str);
        return true;
    }

    bool is_open() const{
        return is_open_;
    }

    std::string getPath() const{
        return path_;
    }

private:
    std::string path_;
    bool is_open_;
    std::ifstream file_;

    FileReader(const FileReader & fr);
    FileReader& operator=(const FileReader & fr);
};