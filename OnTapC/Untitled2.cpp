//doc file tu dien

void Doc_file(string fn){
    ifstream f1;
    f1.open(fn);
    if(! f1.is_open())
    {
        cout<<"Khong the mo file.\n";
        return;
    }
    vector<Tudien>tudiens;
    string line;

        while (getline(f1, line)) {
            size_t pos = line.find(",");
            Tudien x;

            x.Name = line.substr(0, pos);
            line.erase(0, pos + 1);

            x.Meaning = line.substr(0, pos);

            tudiens.push_back(x);
        }
    int n =  tudiens.size() - 1;
}
//doc_file num
ifstream f1;
    f1.open(fn);
    if(! f1.is_open())
    {
        cout<<"Khong the mo file.\n";
        return;
    }
    int num;
    vector<int>A;
    while(f1 >> num){
        A.push_back(num);
    }
    
    f1.close();
