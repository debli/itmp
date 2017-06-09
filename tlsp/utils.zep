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
    
    protected instance;

    abstract protected function initHashKey();

    public function __construct(array! srvCfg = [], string! vType = "")
    {
        if !function_exists("openssl_encrypt")
        {
            throw new Exception("Openssl extension is required!");
        }

        if !extension_loaded("Redis")
        {
            throw new Exception("Redis extension is required");
        }
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

    protected function _get(string! key) -> string
    {
        if this->instance === null
        {
            throw new Exception("Redis instance is null!");
        }

        return this->instance->hGet(this->hashKey, key);
    }

    protected function _set(string key, string! v) -> bool
    {
        return this->instance->_push();
    }

/*
    protected function changeHashKey(string! key) -> void
    {
        this->hashKey = key; 
    }
    */

/*
    private function encrypt(string! str, string! method, string! key, string! iv)
    {
        return openssl_encrypt(str, method, key, OPENSSL_RAW_DATA, iv);
    }

    private function decrypt(string! encrypted, string! method, string! key, string! iv)
    {
        return openssl_decrypt(encrypted, method, key, OPENSSL_RAW_DATA, iv);
    }
    */

}
