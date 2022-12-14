//
// Generated file, do not edit! Created by nedtool 5.7 from DolevStrong.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "DolevStrong_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(DolevStrongMsg)

DolevStrongMsg::DolevStrongMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

DolevStrongMsg::DolevStrongMsg(const DolevStrongMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

DolevStrongMsg::~DolevStrongMsg()
{
    delete [] this->signature;
}

DolevStrongMsg& DolevStrongMsg::operator=(const DolevStrongMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void DolevStrongMsg::copy(const DolevStrongMsg& other)
{
    this->source = other.source;
    this->signCount = other.signCount;
    delete [] this->signature;
    this->signature = (other.signature_arraysize==0) ? nullptr : new int[other.signature_arraysize];
    signature_arraysize = other.signature_arraysize;
    for (size_t i = 0; i < signature_arraysize; i++) {
        this->signature[i] = other.signature[i];
    }
    this->round = other.round;
    this->value = other.value;
    this->messageType = other.messageType;
}

void DolevStrongMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->source);
    doParsimPacking(b,this->signCount);
    b->pack(signature_arraysize);
    doParsimArrayPacking(b,this->signature,signature_arraysize);
    doParsimPacking(b,this->round);
    doParsimPacking(b,this->value);
    doParsimPacking(b,this->messageType);
}

void DolevStrongMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->source);
    doParsimUnpacking(b,this->signCount);
    delete [] this->signature;
    b->unpack(signature_arraysize);
    if (signature_arraysize == 0) {
        this->signature = nullptr;
    } else {
        this->signature = new int[signature_arraysize];
        doParsimArrayUnpacking(b,this->signature,signature_arraysize);
    }
    doParsimUnpacking(b,this->round);
    doParsimUnpacking(b,this->value);
    doParsimUnpacking(b,this->messageType);
}

int DolevStrongMsg::getSource() const
{
    return this->source;
}

void DolevStrongMsg::setSource(int source)
{
    this->source = source;
}

int DolevStrongMsg::getSignCount() const
{
    return this->signCount;
}

void DolevStrongMsg::setSignCount(int signCount)
{
    this->signCount = signCount;
}

size_t DolevStrongMsg::getSignatureArraySize() const
{
    return signature_arraysize;
}

int DolevStrongMsg::getSignature(size_t k) const
{
    if (k >= signature_arraysize) throw omnetpp::cRuntimeError("Array of size signature_arraysize indexed by %lu", (unsigned long)k);
    return this->signature[k];
}

void DolevStrongMsg::setSignatureArraySize(size_t newSize)
{
    int *signature2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = signature_arraysize < newSize ? signature_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        signature2[i] = this->signature[i];
    for (size_t i = minSize; i < newSize; i++)
        signature2[i] = 0;
    delete [] this->signature;
    this->signature = signature2;
    signature_arraysize = newSize;
}

void DolevStrongMsg::setSignature(size_t k, int signature)
{
    if (k >= signature_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->signature[k] = signature;
}

void DolevStrongMsg::insertSignature(size_t k, int signature)
{
    if (k > signature_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = signature_arraysize + 1;
    int *signature2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        signature2[i] = this->signature[i];
    signature2[k] = signature;
    for (i = k + 1; i < newSize; i++)
        signature2[i] = this->signature[i-1];
    delete [] this->signature;
    this->signature = signature2;
    signature_arraysize = newSize;
}

void DolevStrongMsg::insertSignature(int signature)
{
    insertSignature(signature_arraysize, signature);
}

void DolevStrongMsg::eraseSignature(size_t k)
{
    if (k >= signature_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = signature_arraysize - 1;
    int *signature2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        signature2[i] = this->signature[i];
    for (i = k; i < newSize; i++)
        signature2[i] = this->signature[i+1];
    delete [] this->signature;
    this->signature = signature2;
    signature_arraysize = newSize;
}

int DolevStrongMsg::getRound() const
{
    return this->round;
}

void DolevStrongMsg::setRound(int round)
{
    this->round = round;
}

int DolevStrongMsg::getValue() const
{
    return this->value;
}

void DolevStrongMsg::setValue(int value)
{
    this->value = value;
}

int DolevStrongMsg::getMessageType() const
{
    return this->messageType;
}

void DolevStrongMsg::setMessageType(int messageType)
{
    this->messageType = messageType;
}

class DolevStrongMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_source,
        FIELD_signCount,
        FIELD_signature,
        FIELD_round,
        FIELD_value,
        FIELD_messageType,
    };
  public:
    DolevStrongMsgDescriptor();
    virtual ~DolevStrongMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(DolevStrongMsgDescriptor)

DolevStrongMsgDescriptor::DolevStrongMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DolevStrongMsg)), "omnetpp::cMessage")
{
    propertynames = nullptr;
}

DolevStrongMsgDescriptor::~DolevStrongMsgDescriptor()
{
    delete[] propertynames;
}

bool DolevStrongMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DolevStrongMsg *>(obj)!=nullptr;
}

const char **DolevStrongMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DolevStrongMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DolevStrongMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int DolevStrongMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_source
        FD_ISEDITABLE,    // FIELD_signCount
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_signature
        FD_ISEDITABLE,    // FIELD_round
        FD_ISEDITABLE,    // FIELD_value
        FD_ISEDITABLE,    // FIELD_messageType
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *DolevStrongMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "source",
        "signCount",
        "signature",
        "round",
        "value",
        "messageType",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int DolevStrongMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "source") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "signCount") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "signature") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "round") == 0) return base+3;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+4;
    if (fieldName[0] == 'm' && strcmp(fieldName, "messageType") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DolevStrongMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_source
        "int",    // FIELD_signCount
        "int",    // FIELD_signature
        "int",    // FIELD_round
        "int",    // FIELD_value
        "int",    // FIELD_messageType
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **DolevStrongMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DolevStrongMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DolevStrongMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DolevStrongMsg *pp = (DolevStrongMsg *)object; (void)pp;
    switch (field) {
        case FIELD_signature: return pp->getSignatureArraySize();
        default: return 0;
    }
}

const char *DolevStrongMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DolevStrongMsg *pp = (DolevStrongMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DolevStrongMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DolevStrongMsg *pp = (DolevStrongMsg *)object; (void)pp;
    switch (field) {
        case FIELD_source: return long2string(pp->getSource());
        case FIELD_signCount: return long2string(pp->getSignCount());
        case FIELD_signature: return long2string(pp->getSignature(i));
        case FIELD_round: return long2string(pp->getRound());
        case FIELD_value: return long2string(pp->getValue());
        case FIELD_messageType: return long2string(pp->getMessageType());
        default: return "";
    }
}

bool DolevStrongMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DolevStrongMsg *pp = (DolevStrongMsg *)object; (void)pp;
    switch (field) {
        case FIELD_source: pp->setSource(string2long(value)); return true;
        case FIELD_signCount: pp->setSignCount(string2long(value)); return true;
        case FIELD_signature: pp->setSignature(i,string2long(value)); return true;
        case FIELD_round: pp->setRound(string2long(value)); return true;
        case FIELD_value: pp->setValue(string2long(value)); return true;
        case FIELD_messageType: pp->setMessageType(string2long(value)); return true;
        default: return false;
    }
}

const char *DolevStrongMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *DolevStrongMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DolevStrongMsg *pp = (DolevStrongMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

