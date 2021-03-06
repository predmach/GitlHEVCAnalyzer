#include "refreshscreencommand.h"
#include "model/modellocator.h"
#include <QPixmap>
RefreshScreenCommand::RefreshScreenCommand(QObject *parent) :
    GitlAbstractCommand(parent)
{

}

bool RefreshScreenCommand::execute( GitlCommandParameter& rcInputArg, GitlCommandParameter& rcOutputArg )
{
    ModelLocator* pModel = ModelLocator::getInstance();
    int iPoc = pModel->getFrameBuffer().getPoc();
    QPixmap* pcFramePixmap = pModel->getFrameBuffer().getFrame(iPoc);
    pcFramePixmap = pModel->getDrawEngine().drawFrame(&(pModel->getSequenceManager().getCurrentSequence()), iPoc, pcFramePixmap);  ///< Draw Frame Buffer

    ///
    rcOutputArg.setParameter("picture",  QVariant::fromValue((void*)(pcFramePixmap)));

    return true;
}
