class Image{
	public:
	virtual void draw() const = 0;
	~Image() = 0;
};
class MetaData;
class BitImage:Image{
	MetaData m_metaData;
	vector<vector<int>> image;
	public:
	BitImage(MetaData metaData):m_metaData(metaData){
		// loading image
	}
	void draw() override{
		// drawing image
	}
};
