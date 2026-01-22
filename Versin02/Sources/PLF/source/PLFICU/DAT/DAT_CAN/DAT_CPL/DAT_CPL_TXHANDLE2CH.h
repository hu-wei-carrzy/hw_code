
#ifndef DAT_CPL_TXHANDLE2CH_H
#define DAT_CPL_TXHANDLE2CH_H

#define cLDBChannelCanPosHolder       ((U8)0xFFU)
#define cU8MaxTxHandle                ((U8)8U)

static const U8 scu8TxHandle2Ch[8] =
{
    cLDBChannelCanPosHolder,
    cLDBChannelCanPosHolder,
    cLDBChannelCan1,
    cLDBChannelCan1,
    cLDBChannelCan1,
    cLDBChannelCan1,
    cLDBChannelCan1,
    cLDBChannelCan1,

};


static const U8 su8TxHandle2TxMsgLng[8]  =
{
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,

};
#endif
