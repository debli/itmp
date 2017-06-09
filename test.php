<?php

$utils = new Tlsp\Utils();
echo $utils->alpha('nihao');
$utils->initCfg('127.0.0.1', 6379);
echo @openssl_encrypt('abcd', 'AES-128-CBC', 'aaa');

echo $utils->getHash('_products', '1');
