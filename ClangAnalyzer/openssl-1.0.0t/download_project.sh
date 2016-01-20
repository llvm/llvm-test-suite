EXPECTED_MD5="7b7e9f6039a97e4a453b596055912435"
curl -L -O https://www.openssl.org/source/openssl-1.0.0t.tar.gz
if [[ $(md5 -q openssl-1.0.0t.tar.gz) != $EXPECTED_MD5 ]]; then
  echo "Unexpected source hash"
  exit -1
fi

tar zxvf openssl-1.0.0t.tar.gz
mv openssl-1.0.0t CachedSource


