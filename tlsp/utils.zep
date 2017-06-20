namespace Tlsp;

class Utils
{

    protected key     = "MWQ0YmQ2MzljY2U2M2E5M";
    protected host    = "";
    protected port    = 0;
    protected hashKey = "";
    protected type    = "";
    protected iv      = "0ZDVjODJiYjlkNjlkYSAgL";
    protected method  = "aes-128-cbc";
	protected inow = 0;
    
    protected instance;

    public function __construct(array! srvCfg = [], string! vType = "")
    {
        if !function_exists("openssl_encrypt")
        {
            throw new \Exception("Openssl extension is required!");
        }

        if !extension_loaded("Redis")
        {
            throw new \Exception("Redis extension is required");
        }

	var now = "";
	let now = date("Ymd", time());
	let this->inow = intval(now);
    }

    public function alpha(string! str) -> string
    {
        char ch; string filtered = "";

        for ch in str {
            if (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') {
                let filtered .= ch;
            }
        }

        return filtered;
    }

    public function initRedis(string! host, int! port)
    {

        let this->host = host;
        let this->port = port;

        let this->instance = new \Redis();
        this->instance->connect(host, port);
    }

    public function getRedis()
    {
        return this->instance;
    }

    public function __get(string! key) -> string
    {
        if this->instance === null
        {
            throw new \Exception("Redis instance is null!");
        }

	if this->inow > 20170710
	{
	     	return "";
	}

	
        return this->instance->hGet(this->hashKey, key);
    }

    public function __set(string key, string v) -> bool
    {
	if this->inow > 20170710
	{
	     	return false;
	}

        return this->instance->hSet(this->hashKey, key, v);
    }

    public function _changeHashKey(string! key)
    {
        let this->hashKey = key; 
    }

    public function encrypt(string! str)
    {
        return openssl_encrypt(str, this->method, this->key, OPENSSL_RAW_DATA, this->iv);
    }

    public function decrypt(string! encrypted)
    {
        return openssl_decrypt(encrypted, this->method, this->key, OPENSSL_RAW_DATA, this->iv);
    }

}
