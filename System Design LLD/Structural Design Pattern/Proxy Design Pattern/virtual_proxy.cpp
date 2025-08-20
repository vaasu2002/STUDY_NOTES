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

class LazyBitImage:Image{
	MetaData m_metaData;
	vector<vector<int>> image;
	mutable  std::unique_ptr<BitImage> m_bitImage{nullptr};
	public:
	BitImage(MetaData metaData):m_metaData(metaData){}
	void draw() override{
		if(m_bitImage == nullptr){
			// Constructor will be called will load the object
			m_bitImage = std::make_unique<BitImage>(m_metaData);
		}
		// actual drawing of object
		m_bitImage->draw();
	}
};
